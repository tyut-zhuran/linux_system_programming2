//jiffies:linux中用来记录以节拍时间为单位的时间记录
//开机时它有一个基准值，经过一个节拍时间后加1
//
//linux内核开机启动时会从RTC获取一个基准时间信息，
//于是从该信息中减去1970-1-1 00:00:00 +0000 得出其jiffies
//的值（类似于所谓的Unix时间戳？）
//
//常用API和库函数：
//time返回当前时间距离1970...的秒数
//ctime
//
//gmtime:国际时间
//localtime:当前系统时间
//它们返回struct tm  具体man 3 ctime
//
//
//asctime和strftime可从struct tm获取字符串格式的时间
//
//
//还有gettimeofday\settimeofday等
//
//
//所有的时间信息都是从jiffies中获得的
//
//
//

