/** @prettier */

const OPTS = require('./options.js');

const pkg = require('../package.json');
const path = require('path');
const merge = require('webpack-merge');
const common = require('./webpack.common.js');
const autoprefixer = require('autoprefixer');

module.exports = merge(common, {
  mode: 'development',
  output: {
    path: path.resolve(__dirname, '..', pkg.config.dist_dir),
    filename: OPTS.BASE_OUT_NAME + '.min.js',
    libraryTarget: 'window',
    library: OPTS.LIBRARY_NAME
  },
  module: {
    rules: [
      {
        test: /\.scss$/,
        exclude: /node_modules/,
        use: [
          {
            loader: 'css-loader',
            options: {
              url: false,
              sourceMap: true
            }
          },
          {
            loader: 'postcss-loader',
            options: {
              plugins: [autoprefixer()],
              sourceMap: 'inline'
            }
          },
          {
            loader: 'sass-loader',
            options: {
              data: '$env: "development";',
              outputStyle: 'expanded',
              sourceMap: true
            }
          }
        ]
      }
    ]
  },
  devtool: 'source-map',
  devServer: {
    contentBase: path.resolve(__dirname, '..', pkg.config.dist_dir),
    port: OPTS.PORT
  }
});
