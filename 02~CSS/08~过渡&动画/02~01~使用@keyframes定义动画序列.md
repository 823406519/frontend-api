
## 使用@keyframes定义动画序列
@keyframes 使用@keyframes建立两个或两个以上关键帧来定义动画的规则

关键帧使用percentage来指定动画发生的时间点。0%表示动画的第一时刻，100%表示动画的最终时刻。因为这两个时间点十分重要，所以还有特殊的别名：from和to
```css
@keyframes foo{
    /* 不同时间段的样式规则 */
    from{
        /* 样式属性 */
    },
    50%{
        /* 样式属性 */
    },
    to{
        /* 样式属性 */
    }
    /* 其中 from 相当于 0% */
    /* 其中 to 相当于 100% */
}
```

## @keyframes 注意事项
1. @keyframes重复定义。如果多个关键帧使用同一个名称，以最后一次定义的为准
2. 当关键帧被重复定义。如果某一个关键帧出现了重复的定义，且重复的关键帧中的css属性值不同，以最后一次定义的属性为准
3. 关键帧中出现的 !important 关键词将会被忽略

