'use strict';

/**
 * MODULES
 */
// Utilities
const gulp = require('gulp');
const del = require('del');
const gulpif = require('gulp-if');

// JS Processing
const babel = require('gulp-babel');
const uglify = require('gulp-uglify');

// Sass Processing
const sass = require('gulp-sass');
const csso = require('gulp-csso');
const sourcemaps = require('gulp-sourcemaps');
const prefix = require('gulp-autoprefixer');

// Image Processing
const imagemin = require('gulp-imagemin');

// Linting
var sasslint = require('gulp-sass-lint');

/**
 * CONFIGURATION
 */
const config = {
  production: process.argv.indexOf('--production') > -1,
  browserList: ['last 2 version', '> 1%', 'ie 11'],
  sass_libraries: {
    includePaths: [
      'node_modules/breakpoint-sass/stylesheets/',
      'node_modules/standardize-sass/stylesheet'
    ]
  },
  src: {
    sass: 'sass/**/*.scss',
    js: 'js/*.js',
    images: 'images/**/*'
  },
  dest: 'build'
};

/**
 * TASKS
 */
// Clean output directories
gulp.task('clean', () => del([config.dest]));

// Sass compiler task
gulp.task('sass', () => gulp.src(config.src.sass)
    .pipe(sourcemaps.init())
    .pipe(sass(config.sass_libraries).on('error', sass.logError)) // Converts Sass to CSS with gulp-sass
    .pipe(prefix(config.browserList))
    .pipe(sourcemaps.write())
    .pipe(gulpif(config.production, csso()))
    .pipe(gulp.dest(config.dest + '/css'))
);

// Javascript transpiling and concatenation task
gulp.task('js', () => gulp.src(config.src.js)
    .pipe(babel({ presets: ["@babel/preset-env"] }))
    .pipe(gulpif(config.production, uglify()))
    .pipe(gulp.dest(config.dest + '/js'))
);

// Image minification task
gulp.task('images', () => gulp.src(config.src.images)
    .pipe(imagemin())
    .pipe(gulp.dest(config.dest + '/images'))
);

// Linting task
gulp.task('lint:sass', () => gulp.src(config.src.sass)
    .pipe(sasslint({
      files: {
        ignore: [
          'sass/style.scss',
          'sass/_print.scss',
          'sass/_variables/__reset.scss']
      },
      configFile: '.sass-lint.yml',
    }))
    .pipe(sasslint.format())
    .pipe(sasslint.failOnError())
);

gulp.task('lint', gulp.parallel(['lint:sass']));

// Watch task runner
gulp.task('watch', (done) => {
  if (!config.production) {
    gulp.watch(config.src.sass, gulp.series('sass'));
    gulp.watch(config.src.js, gulp.series('js'));
    gulp.watch(config.src.images, gulp.series('images'));
  }
  done();
});

/**
 * BUILD
 */
const tasks = [
  'sass',
  'js',
  'images',
  'watch'
];

gulp.task('default', gulp.series('clean', gulp.series(tasks)));

