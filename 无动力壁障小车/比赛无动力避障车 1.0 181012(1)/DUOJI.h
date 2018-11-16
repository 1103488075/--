void MN_DSQ_init()//初始化模拟舵机定时器
{
	
	T0NUM = 0 ;
	
    AUXR = 0x80 ;//不分频，12倍频
    TMOD = 0x02 ;//T0工作在模式3

	TH0 = 0x85 ;
	TL0 = 0x85 ;
    EA = 1 ;//开全局中断
    ET0 = 1 ;//T0中断服务允许开关
    TR0 = 1 ;//开定时器0计时
}
//####################################
void T0GO() interrupt 1 
{
    T0NUM++ ;
	if(T0NUM<JD + 46)//如果低电平时间小于0.5ms + 角度对应高电平时间 ，则输出1
		PWMOUT = 1 ;
	else PWMOUT = 0 ;//否则输出0
	if(T0NUM>1801)//结束一个周期 1801 * 11.1us后结束一个周期 ：20ms
		T0NUM = 0 ;
	
}