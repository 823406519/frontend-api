/*
(0, n-1) 选择最小的放在第一个位置
(1, n-1) 选择最小的放在第二个位置
...

时间复杂度 O(n) -> O(n2), 与数据状况有关，按最差的排序
*/

function selectSort(arr) {
  if (arr.length < 2) return;

  for (let start = 0; start < arr.length - 1; start++) {
    minIndex = start;
    for (let j = start + 1; j < arr.length; j++) {
      minIndex = arr[j] < arr[minIndex] ? j : minIndex;
    }
    if (minIndex != start) {
      [arr[minIndex], arr[start]] = [arr[start], arr[minIndex]];
    }
  }
}

let arr = [3, 9, 8, 7, 1];

selectSort(arr);
console.log(arr);
