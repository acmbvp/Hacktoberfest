/** @prettier */

const OPTS = require('./options.js');

const pkg = require('../package.json');
const path = require('path');
const webpack = require('webpack');
const merge = require('webpack-merge');
const common = require('./webpack.common.js');
const autoprefixer = require('autoprefixer');
const UglifyJsPlugin = require('uglifyjs-webpack-plugin');

const _config = merge(common, {
  mode: 'production',
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
              sourceMap: false
            }
          },
          {
            loader: 'postcss-loader',
            options: {
              plugins: [autoprefixer()],
              sourceMap: false
            }
          },
          {
            loader: 'sass-loader',
            options: {
              data: '$env: "production";',
              outputStyle: 'compressed',
              sourceMap: false
            }
          }
        ]
      }
    ]
  },
  devtool: 'source-map',
  plugins: [
    new UglifyJsPlugin({
      sourceMap: true,
      uglifyOptions: {
        ecma: 8,
        output: {
          comments: 'some'
        }
      }
    }),
    new webpack.BannerPlugin({
      banner: `${pkg.name} v${pkg.version} ${pkg.author} | ${pkg.license}`
    })
  ]
});

const config = [
  merge(_config, {
    output: {
      path: path.resolve(__dirname, '..', pkg.config.dist_dir),
      filename: OPTS.BASE_OUT_NAME + '.umd.js',
      libraryTarget: 'umd',
      library: OPTS.LIBRARY_NAME,
      umdNamedDefine: true
    }
  }),
  merge(_config, {
    output: {
      path: path.resolve(__dirname, '..', pkg.config.dist_dir),
      filename: OPTS.BASE_OUT_NAME + '.min.js',
      libraryTarget: 'window',
      library: OPTS.LIBRARY_NAME
    }
  })
];

module.exports = config;
