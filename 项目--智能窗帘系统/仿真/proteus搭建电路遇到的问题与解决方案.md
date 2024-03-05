# 元器件中英文对应
| 按钮 | button |
| --- | --- |
| 电解电容 | cap-elec |
| 电容 | cap |
| 晶振 | crystal |
| 电阻 | res |
| LCD1602 | lm016l |
| 滑动变阻器 | pot-hg |
| 蜂鸣器 | buzzer |
| 六线四相制的步进电机 | MOTOR-STEPPER |
| 光照电阻 | TORCH_LDR |
| 双通道ADC芯片 | ADC08032 |


# 芯片的晶振问题
在仿真时，芯片并不遵循外部接了什么频率的晶振来运行，而是通过芯片内部的参数来运行
![image.png](https://cdn.nlark.com/yuque/0/2024/png/32837498/1706514405297-304cb48a-a971-42c0-a21c-deab206c9ab4.png#averageHue=%23e9e8e7&clientId=u90faea08-1fd1-4&from=paste&height=413&id=ubf9edf61&originHeight=413&originWidth=527&originalType=binary&ratio=1&rotation=0&showTitle=false&size=25407&status=done&style=none&taskId=u7fae8082-4f5c-4105-93ba-361db17094e&title=&width=527)

# 关于蜂鸣器的设置
蜂鸣器默认驱动电压为12V，改成5V后可以正常鸣叫。
![image.png](https://cdn.nlark.com/yuque/0/2024/png/32837498/1706601358135-2419c7c8-0472-400f-94c2-c1a524c2be71.png#averageHue=%23e9dfdd&clientId=udb61dd85-c1fa-4&from=paste&height=437&id=u17995bd1&originHeight=437&originWidth=495&originalType=binary&ratio=1&rotation=0&showTitle=false&size=26002&status=done&style=none&taskId=uaccea6d2-d452-41ce-886e-62b703122f4&title=&width=495)

# 如何设置网络编号
在proteus软件中，点击键盘中的`a`后将字符串改为`net=P#`，然后点击引线，就会标记成功，当图中存在两个及以上同样标记的引线时，就导通了，可以再按一下`a`来关闭编号功能。
# 如何画框与文字，来进行模块分区
选择`二维方框图形模式`后，选择`PIN`方式后，即可画出框。
![image.png](https://cdn.nlark.com/yuque/0/2024/png/32837498/1706509938634-9c49d4f5-ea62-4155-aea7-8901de35d168.png#averageHue=%23e0decb&clientId=u506e1611-7a12-4&from=paste&height=417&id=u8338c456&originHeight=417&originWidth=214&originalType=binary&ratio=1&rotation=0&showTitle=false&size=20103&status=done&style=none&taskId=uaf6efd6c-9d4e-46de-9a9e-5586f15b90b&title=&width=214)
文字和框基本一样，可以通过调整行高来调整文字大小。

# 参考链接
将10K电阻调低后复位电路可正常运行
[PROTEUS中的复位电路_proteus复位电路怎么画-CSDN博客](https://blog.csdn.net/assemble8086/article/details/44057423) 
[步进电机原理 Proteus仿真及硬件实现（详细）_28byj48在proteus中的名称-CSDN博客](https://blog.csdn.net/weixin_44509533/article/details/106816106)
[Proteus设置网络标签_proteus网络标号怎么弄-CSDN博客](https://blog.csdn.net/weixin_64151251/article/details/133518853#:~:text=%E6%AD%A5%E9%AA%A41%20%E9%80%89%E6%8B%A9%E7%BD%91%E7%BB%9C%E7%AB%AF%E5%8F%A3%20%E9%80%89%E6%8B%A9%E7%BB%88%E7%AB%AF%E6%A8%A1%E5%BC%8F%EF%BC%8C%E7%84%B6%E5%90%8E%E9%80%89%E6%8B%A9DEFAULT%EF%BC%8C%E4%BC%9A%E6%9C%89%E4%B8%80%E4%B8%AA%E7%B1%BB%E4%BC%BC%E7%AB%AF%E5%8F%A3%E7%9A%84%E4%B8%9C%E8%A5%BF%20%E8%BF%99%E4%B8%AA%E6%88%91%E5%B0%B1%E5%85%88%E7%A7%B0%E4%B9%8B%E4%B8%BA%E7%BD%91%E7%BB%9C%E7%AB%AF%E5%8F%A3%E4%BA%86%EF%BC%8C%E4%B9%9F%E4%B8%8D%E6%98%AF%E5%BE%88%E6%B8%85%E6%A5%9A%E5%85%B7%E4%BD%93%E5%8F%AB%E4%BB%80%E4%B9%88%20%E6%AD%A5%E9%AA%A42%20%E6%94%BE%E7%BD%AE%E7%BD%91%E7%BB%9C%E7%AB%AF%E5%8F%A3%20%E5%9C%A8%E9%9C%80%E8%A6%81%E9%93%BE%E6%8E%A5%E7%9A%84%E4%B8%A4%E7%AB%AF%E5%88%86%E5%88%AB%E9%83%BD%E8%A6%81%E6%94%BE%E4%B8%8A%E7%BD%91%E8%B7%AF%E7%AB%AF%E5%8F%A3%EF%BC%88%E6%88%91%E8%BF%99%E9%87%8C%E5%8F%AA%E5%B1%95%E7%A4%BA%E4%BA%86%E4%B8%80%E8%BE%B9%EF%BC%89%20%E6%AD%A5%E9%AA%A43,%E9%94%AE%E7%9B%98%E8%BE%93%E5%85%A5%E6%B3%95%E5%88%87%E6%8D%A2%E5%88%B0%20%E8%8B%B1%E6%96%87%E6%A8%A1%E5%BC%8F%20%EF%BC%8C%E7%84%B6%E5%90%8E%E5%9C%A8%20%E9%94%AE%E7%9B%98%E4%B8%8A%E6%8C%89%E4%B8%8BA%20%EF%BC%88%E5%A4%A7%E5%B0%8F%E5%86%99%E9%83%BD%E5%8F%AF%E4%BB%A5%EF%BC%89%EF%BC%8C%E4%BC%9A%E8%B7%B3%E5%87%BA%E5%B1%9E%E6%80%A7%E8%B5%8B%E5%80%BC%E5%B7%A5%E5%85%B7%E8%BF%99%E4%B8%AA%E7%95%8C%E9%9D%A2%20%E9%BC%A0%E6%A0%87%E6%94%BE%E5%9C%A8%E9%9C%80%E8%A6%81%E6%A0%87%E5%8F%B7%E7%9A%84%E4%BD%8D%E7%BD%AE%E4%B8%8A%E4%BC%9A%E5%87%BA%E7%8E%B0%E4%B8%80%E4%B8%AA%E7%BB%BF%E8%89%B2%E7%9A%84%E5%B0%8F%E7%AD%89%E5%8F%B7%EF%BC%8C%E5%8D%95%E5%87%BB%E5%8D%B3%E5%8F%AF%E8%AE%BE%E7%BD%AE%E6%A0%87%E7%AD%BE%EF%BC%8C%EF%BC%88%20%E8%AE%B0%E5%BE%97%E5%9C%A8%E9%9C%80%E8%A6%81%E8%BF%9E%E6%8E%A5%E7%9A%84%E4%B8%A4%E7%AB%AF%E9%83%BD%E8%A6%81%E8%BF%9B%E8%A1%8C%E6%A0%87%E5%8F%B7%EF%BC%8C%E8%80%8C%E4%B8%94%E4%B8%A4%E8%BE%B9%E7%9A%84%E6%A0%87%E5%8F%B7%E9%9C%80%E8%A6%81%E4%B8%80%E6%A0%B7%E6%89%8D%E8%83%BD%E5%8F%91%E6%8C%A5%E4%BD%9C%E7%94%A8%20%EF%BC%89%E3%80%82)
参考ADC代码
[毕业设计之光照感应模块ADC0832的运用_adc0832应用电路-CSDN博客](https://blog.csdn.net/qq_38173631/article/details/105605299) 
评论区解决仿真报错
[proteus 出现 No model specified for D1和Simulation FAILED due to partition analysis error(s)错误-CSDN博客](https://blog.csdn.net/weixin_49148987/article/details/131816450)

