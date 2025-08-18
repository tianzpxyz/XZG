#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Ask for confirmation to pull changes
echo -e "${YELLOW}Do you want to pull the latest changes from the repository? 🔄 (Y/n)${NC}"
read -r response
response=${response:-y} # default 'yes' if empty
if [[ "$response" =~ ^[Yy]$ ]]; then
    git pull
    echo -e "${GREEN}Changes pulled successfully. ✔️${NC}"
else
    echo -e "${YELLOW}Pull skipped. Continuing without pulling changes. ⚠️${NC}"
fi

# Adding all changes to staging
git add -A
echo -e "${GREEN}All changes added to staging. ✔️${NC}"

# Path to the version and commit message files
COMMIT_MESSAGE_FILE="commit.md"
VERSION_HEADER="src/version.h"

# Check if the version file exists
if [ ! -f "$VERSION_HEADER" ]; then
    echo -e "${RED}Version header not found: $VERSION_HEADER ❌${NC}"
    exit 1
fi

# Read version from the version file
version=$(grep '#define VERSION' "$VERSION_HEADER" | awk -F '"' '{print $2}')

tag=$version

regex='^(.+)\.([0-9]+)$'

if [[ $tag =~ $regex ]]; then
    base=${BASH_REMATCH[1]}
    suffix=${BASH_REMATCH[2]}
else
    base=$tag
    suffix=0
fi

while git rev-parse "$tag" >/dev/null 2>&1; do
    suffix=$((suffix + 1))
    tag="${base}.${suffix}"
done

sed -i.bak "s/#define VERSION \"${version}\"/#define VERSION \"${tag}\"/" "$VERSION_HEADER"

rm "${VERSION_HEADER}.bak"

echo "Updated version to $tag in $VERSION_HEADER"

# Checking for commit message file
if [ -f "$COMMIT_MESSAGE_FILE" ]; then
    echo -e "${YELLOW}Commit message file found. Do you want to use the existing commit message? (y/N) 📝${NC}"
    read -r useExistingMessage
    useExistingMessage=${useExistingMessage:-n} # default 'no' if empty
    if [[ "$useExistingMessage" =~ ^[Yy]$ ]]; then
        commitMessage=$(cat "$COMMIT_MESSAGE_FILE")
        # Prepend version to the commit message with a newline for separation
        formattedCommitMessage="${tag}
        ${commitMessage}"
        # Cleaning up the commit message file, if used
        if [ -f "$COMMIT_MESSAGE_FILE" ]; then
            tools/clean_file.sh "$COMMIT_MESSAGE_FILE"
        fi
    else
        echo -e "${YELLOW}Please enter your commit message: 📝${NC}"
        read -r commitMessage
        formattedCommitMessage="${commitMessage}"
    fi
else
    echo -e "${YELLOW}Commit message file not found. Please enter your commit message: 📝${NC}"
    read -r commitMessage
    formattedCommitMessage="${commitMessage}"
fi

# Committing changes
git commit -m "$formattedCommitMessage"
echo -e "${GREEN}Changes committed with version prepended to message: ✔️${NC}"

# Tagging process
echo -e "${YELLOW}Do you want to create a new release by publishing a tag? 🏷️ (y/N)${NC}"
read -r tagCommit
tagCommit=${tagCommit:-n} # default 'no' if empty
if [[ "$tagCommit" =~ ^[Yy]$ ]]; then
    git tag "$tag"
    echo -e "${GREEN}Tag assigned: $tag 🏷️${NC}"
    
    # Pushing changes and tag
    echo -e "${YELLOW}Do you want to push the changes and the new tag to the remote repository? 🚀 (Y/n)${NC}"
    read -r pushChanges
    pushChanges=${pushChanges:-y} # default 'yes' if empty
    if [[ "$pushChanges" =~ ^[Yy]$ ]]; then
        git push
        git push origin "$tag"
        echo -e "${GREEN}Changes and new tag pushed successfully. ✔️${NC}"
    else
        echo -e "${RED}Push of changes and tag skipped. ❌${NC}"
    fi
else
    echo -e "${YELLOW}No new release will be created. Do you still want to push the changes? (Y/n) 🚀${NC}"
    read -r pushChanges
    pushChanges=${pushChanges:-y} # default 'yes' if empty
    if [[ "$pushChanges" =~ ^[Yy]$ ]]; then
        git push
        echo -e "${GREEN}Changes pushed successfully without creating a new release. ✔️${NC}"
    else
        echo -e "${RED}Push skipped. ❌${NC}"
    fi
fi

