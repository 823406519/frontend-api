console.log('global begin ' + i)
var i = 1
foo(1)

function foo(i) {
  if (i == 4) return
  console.log('foo begin ' + i)
  foo(i + 1)
  console.log('foo end ' + i)
}
console.log('global begin ' + i)
/**
 * global begin undefined
 * foo begin 1
 * foo begin 2
 * foo begin 3
 * foo end 3
 * foo end 2
 * foo end 1
 * global end 1
 */
