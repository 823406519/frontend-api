function mergeSort(arr, left, right) {
  if (left >= right) return;
  let mid = ~~((left + right) / 2);
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

function merge(arr, left, mid, right) {
  // 新建一个排序辅助数组
  let help = [];
  // 两个指针分别指向左右两个有序数组开端
  let p1 = left;
  let p2 = mid + 1;
  // p1 或者 p2 有一个会到达末端
  while (p1 <= mid && p2 <= right) {
    help.push(arr[p1] > arr[p2] ? arr[p2++] : arr[p1++]);
  }
  // p2 到达末端，那么就使用p1剩余序列放到辅助数组中
  while (p1 <= mid) {
    help.push(arr[p1++]);
  }
  // p1 到达末端，那么就使用p2剩余序列放到辅助数组中
  while (p2 <= right) {
    help.push(arr[p2++]);
  }
  // 将arr中数组修改为辅助数组的值，使得left到right有序
  help.forEach((value, index) => {
    arr[left + index] = value;
  });
}

let arr = [3, 9, 8, 7, 1];
let arr2 = [2, 5, 3, 6, 9];
mergeSort(arr, 0, arr.length - 1);
mergeSort(arr2, 0, arr.length - 1);
console.log(arr);
console.log(arr2);
