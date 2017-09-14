#include "recv.h"

int nFd = 0;
struct termios stNew;
struct termios stOld;

//Open Port & Set Port
int SerialInit()
{
  nFd = open(DEVICE, O_RDWR|O_NOCTTY|O_NDELAY);
  if(-1 == nFd)
  {
    perror("Open Serial Port Error!\n");
    return -1;
  }
  if( (fcntl(nFd, F_SETFL, 0)) < 0 )
  {
    perror("Fcntl F_SETFL Error!\n");
    return -1;
  }
  if(tcgetattr(nFd, &stOld) != 0)
  {
    perror("tcgetattr error!\n");
    return -1;
  }

  stNew = stOld;
  cfmakeraw(&stNew);//���ն�����Ϊԭʼģʽ����ģʽ�����е������������ֽ�Ϊ��λ������

  //set speed
  cfsetispeed(&stNew, BAUDRATE);
  cfsetospeed(&stNew, BAUDRATE);

  //set databits  
  stNew.c_cflag |= (CLOCAL|CREAD);
  stNew.c_cflag &= ~CSIZE;
  stNew.c_cflag |= CS8;

  //set parity  
  stNew.c_cflag &= ~PARENB;  
  stNew.c_iflag &= ~INPCK;

  //set stopbits  
  stNew.c_cflag &= ~CSTOPB;
  stNew.c_cc[VTIME]=0;	//ָ����Ҫ��ȡ�ַ�����С����
  stNew.c_cc[VMIN]=1;	//ָ����ȡ��һ���ַ��ĵȴ�ʱ�䣬ʱ��ĵ�λΪn*100ms
        //�������VTIME=0�������ַ�����ʱread�������������ڵ�����
  tcflush(nFd,TCIFLUSH);	//����ն�δ��ɵ�����/����������ݡ�
  if( tcsetattr(nFd,TCSANOW,&stNew) != 0 )
  {
    perror("tcsetattr Error!\n");
    return -1;
  }

  return nFd;
}

int main(int argc, char **argv)
{
  int nRet = 0, n = 0;
  char buf[SIZE];

  if( SerialInit() == -1 )
  {
    perror("SerialInit Error!\n");
    return -1;
  }

  bzero(buf, SIZE);
  while(1)
  {
    nRet = write(nFd, buf, SIZE);
    if(-1 == nRet)
    {
      perror("Read Data Error!\n");
      break;
    }
    if(0 < nRet)
    {
//	i = 0;
//	buf[nRet] = 0;
//	printf("Recv Data: ");
//	while (buf[i] != 0)
//	{
//	    printf("%c", buf[i]);
//	    i++;
//	}
//	putchar('\n');
        buf[nRet] = 0;
	n = write(nFd, buf, nRet);
	printf("Recv Data: %s\n", buf);
     //  printf("Recv Data: %d\n", nRet);
    }
  }

  close(nFd);
  return 0;
}
