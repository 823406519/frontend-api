
## HTTP1.1 缺陷
HTTP1.1 出现后：
* 传输数据大小和请求资源数量逐渐增长
* 从当初网页内容以文本为主,到现在以富媒体（如图片、声音、视频）为主,而且对页面内容实时性高要求的应用越来越多(比如聊天、视频直播)等HTTP1.1规定的某些特性，已经无法满足现代网络的需求了

HTTP1.1的缺陷主要表现在：
* 延迟高，降低了页面的加载速度。网络延迟问题主要由于队头阻塞(队头阻塞是指当顺序发送的请求序列中的一个请求因为某种原因被阻塞时，在后面排队的所有请求也一并被阻塞),导致带宽无法被充分利用。从理论上讲，可以使用几个并行连接（通常在5到8之间），但带来相当大的开销和复杂性（例如，HTTP管道已成为Web开发中的资源负担）

* 无状态，需要携带"User Agent""Cookie""Accept""Server"等许多固定的头字段

* 明文传输，带来的不安全性

* 不支持服务器推送消息