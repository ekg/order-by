#!/usr/bin/env node

var orderBy = require('order-by')
var fs = require('fs')
var csvparse = require('csv-parse')

if (process.argv.length < 5) {
  console.log('usage:', process.argv[0], process.argv[1], '[file1]', '[column]', '[file2]')
  console.log('    sort the first tab-separated file according to the order of the field [column] in the second file')
  process.exit(1)
}


var file1 = process.argv[2]
var key = process.argv[3] - 1
var file2 = process.argv[4]
var input = []
var order = []
var output = []

function readDelim(filename, result, cb) {
  var parser = csvparse({delimiter:'\t'})
  var file = fs.createReadStream(filename)
  parser.on('readable', function(){
    while(record = parser.read()){
      result.push(record)
    }
  })
  file.on('end', function(){
    cb()
  })
  file.pipe(parser)
}

readDelim(file1, input, function() {
  readDelim(file2, order, function() {
    orderBy(input, key, order).map(function(row) {
      console.log(row.join('\t'))
    })
  })
})
