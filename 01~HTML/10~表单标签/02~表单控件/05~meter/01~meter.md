
## meter
`<meter>` 标签用来显示已知范围的标量值

常用属性：
* value：当前的数值。如果设置了最小值和最大值（分别由min属性和max属性定义），它必须介于最小值和最大值之间。默认的min和max值分别为0和1
* min：值域的最小边界值。如果设置了，它必须比最大值要小。如果没设置，默认为0。
* max：值域的上限边界值。如果设置了，它必须比最小值要大。如果没设置，默认为1。
* low：定义了低值区间的上限值，如果value介于min和low之间，该元素就会表现出低值的视觉效果
* high：定义了高值区间的下限值，如果value介于high和max之间，该元素就会表现出低值的视觉效果
```html
<!-- <meter>元素 -->
<meter min="200" max="500" value="350">350 degrees</meter>
```