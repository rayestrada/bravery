# Chief Drupal 8 Theme

## Global Requirements
Node ^8 (prefer Node 10)

## Installation

### 1. Update the theme file names
Update naming of files and setttings replacing `chief` with `your_theme_name`

### 2. Install theme dependencies
The gulp file should be all setup for you. All you should have to do is install the dependencies from package.json locally and remove git tracking on the theme.
```
npm install
```

### 3. Remove git tracking with the base theme repo
```
rm -rf .git
rm .gitignore
```

## Compiling
**Development**: Starts a watch on sass, js and images 
```
npm run gulp
```

**Production**: Compiles and minifies files for final packaging
```
npm run gulp --production
```

## Linting
Lint the sass files to check for standards compliance.
```
npm run gulp lint
```

## Templates

To override template files, copy core `classy` theme template files into this theme's `templates` sub-directory.
