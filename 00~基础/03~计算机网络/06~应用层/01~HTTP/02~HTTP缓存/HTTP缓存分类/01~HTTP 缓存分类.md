
## 缓存分类
按照缓存的使用者，可以分为两大类：
1. 专用缓存。专用缓存专用于单个用户，在用户浏览器的设置中可以看到“缓存”，缓冲中包含用户通过HTTP下载的所有文档，该缓存可用于后退/前进导航，保存，按源查看等
2. 共享代理缓存。用于存储要由多个用户重用的响应。
例如，ISP或您的公司可能已将Web代理设置为本地网络基础结构的一部分，以为许多用户提供服务，从而使受欢迎的资源得以重复使用多次，从而减少了网络流量和延迟


根据是否需要重新向服务器发起请求，缓存分为强制缓存，对比缓存（协商缓存）
1. 强制缓存在缓存数据未失效的情况下，不需要再和服务器发生交互。
2. 协商缓存，需要进行比较判断是否可以使用缓存

两类缓存规则可以同时存在，强制缓存优先级高于协商缓存。当执行强制缓存的规则时，如果强缓存生效，直接使用强缓存，不再执行协商缓存规则。

> `Pragma > Cache-Control > Expires > ETag > Last-Modified`