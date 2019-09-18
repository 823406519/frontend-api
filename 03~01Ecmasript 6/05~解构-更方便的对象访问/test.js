// 对象解构语法在赋值语句的左侧使用对象字面量
let person = {
  name: 'liu',
  age: 24
};
let { name, age, gender = 'man' } = person;
// 象中找到同名属性的变量，自动创建并取得对应的属性值
// 对象中找不到同名属性的变量，自动创建被赋值为undefined, 如果有默认值，则使用默认值

console.log(name, age, gender); // liu 24 man
