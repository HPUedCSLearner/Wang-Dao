// 利用 tail -10 /var/log/messages 可以查看
// 可能是因为我的系统是docker，缺少了和多东西，导致看不到log

#include <syslog.h>
int main()
{
 //openlog("log",LOG_PID|LOG_CONS|LOG_NOWAIT,LOG_USER);
 syslog(LOG_ALERT,"this is alert\n");
 syslog(LOG_INFO,"this is info\n");
 syslog(LOG_DEBUG,"this is debug%d\t %s",10,"aaaa");
 syslog(LOG_ERR,"err");
 syslog(LOG_CRIT,"crit");
 //closelog();
 return 0;
}
