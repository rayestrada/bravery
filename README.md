# Bravery Drupal 8 Theme

## Global Requirements
Node 10

## Installation

### 1. Update the theme file names
Update naming of files and setttings replacing `bravery` with `your_theme_name`

### 2. Install theme dependencies
The gulp file should be all setup for you. 
All you should have to do is install the dependencies from package.json locally 
and remove git tracking on the theme.
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
npm run dev
```

**Production**: Compiles and minifies files for final packaging
```
npm run build
```

## Linting
Lint the sass and js files to check for standards compliance.
```
npm run lint
```

## Templates

To override template files, copy core `classy` theme template files 
into this theme's `templates` sub-directory.
