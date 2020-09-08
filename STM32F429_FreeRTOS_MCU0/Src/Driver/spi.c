#include "marco.h"
#include "spi.h"

SPI_HandleTypeDef SPI5_Handler;
SPI_HandleTypeDef SPI1_Handler;
SPI_HandleTypeDef SPI2_Handler;

//PF6
void SPI5_CSPIN_MCU1_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOF_CLK_ENABLE();
    GPIO_Initure.Pin = GPIO_PIN_6;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initure.Pull = GPIO_PULLUP;
    GPIO_Initure.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(GPIOF, &GPIO_Initure);
}

//PD6
void SPI5_CSPIN_MCU2_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOD_CLK_ENABLE();
    GPIO_Initure.Pin = GPIO_PIN_6;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initure.Pull = GPIO_PULLUP;
    GPIO_Initure.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(GPIOD, &GPIO_Initure);
}

//PA4
void SPI1_CSPIN_MCU1_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_Initure.Pin = GPIO_PIN_4;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initure.Pull = GPIO_PULLUP;
    GPIO_Initure.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(GPIOA, &GPIO_Initure);
}

void SPI5_Init(void)
{
    SPI5_CSPIN_MCU1_Init();
    SPI5_CSPIN_MCU2_Init();
    SPI5_Handler.Instance = SPI5;                                    //SP5
    SPI5_Handler.Init.Mode = SPI_MODE_MASTER;                        //设置SPI工作模式，设置为主模式
    SPI5_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //设置SPI单向或者双向的数据模式:SPI设置为双线模式
    SPI5_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //设置SPI的数据大小:SPI发送接收8位帧结构
    SPI5_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //串行同步时钟的空闲状态为高电平
    SPI5_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //串行同步时钟的第二个跳变沿（上升或下降）数据被采样
    SPI5_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
    SPI5_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256; //定义波特率预分频的值:波特率预分频值为256
    SPI5_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
    SPI5_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //关闭TI模式
    SPI5_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //关闭硬件CRC校验
    SPI5_Handler.Init.CRCPolynomial = 7;                             //CRC值计算的多项式
    HAL_SPI_Init(&SPI5_Handler);                                     //初始化
    __HAL_SPI_ENABLE(&SPI5_Handler);
    //SPI5_ReadWriteByte(0Xff);                           //启动传输
}

void SPI1_Init(void)
{
    SPI1_CSPIN_MCU1_Init();
    SPI1_Handler.Instance = SPI1;                                    //SP1
    SPI1_Handler.Init.Mode = SPI_MODE_MASTER;                        //设置SPI工作模式，设置为主模式
    SPI1_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //设置SPI单向或者双向的数据模式:SPI设置为双线模式
    SPI1_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //设置SPI的数据大小:SPI发送接收8位帧结构
    SPI1_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //串行同步时钟的空闲状态为高电平
    SPI1_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //串行同步时钟的第二个跳变沿（上升或下降）数据被采样
    SPI1_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
    SPI1_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64; //定义波特率预分频的值:波特率预分频值为256
    SPI1_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
    SPI1_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //关闭TI模式
    SPI1_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //关闭硬件CRC校验
    SPI1_Handler.Init.CRCPolynomial = 7;                             //CRC值计算的多项式
    HAL_SPI_Init(&SPI1_Handler);                                     //初始化
    __HAL_SPI_ENABLE(&SPI1_Handler);
    SPI1_ReadWriteByte(0Xff);                           //启动传输
}

void SPI2_Init(void)
{
    SPI1_CSPIN_MCU1_Init();
    SPI2_Handler.Instance = SPI2;                                    //SP2
    SPI2_Handler.Init.Mode = SPI_MODE_MASTER;                        //设置SPI工作模式，设置为主模式
    SPI2_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //设置SPI单向或者双向的数据模式:SPI设置为双线模式
    SPI2_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //设置SPI的数据大小:SPI发送接收8位帧结构
    SPI2_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //串行同步时钟的空闲状态为高电平
    SPI2_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //串行同步时钟的第二个跳变沿（上升或下降）数据被采样
    SPI2_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
    SPI2_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; //定义波特率预分频的值:波特率预分频值为256
    SPI2_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
    SPI2_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //关闭TI模式
    SPI2_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //关闭硬件CRC校验
    SPI2_Handler.Init.CRCPolynomial = 7;                             //CRC值计算的多项式
    HAL_SPI_Init(&SPI2_Handler);                                     //初始化
    __HAL_SPI_ENABLE(&SPI2_Handler);
   // SPI2_ReadWriteByte(0Xff);                           //启动传输
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
    GPIO_InitTypeDef GPIO_Initure;
    if (hspi->Instance == SPI5)
    {
        __HAL_RCC_GPIOF_CLK_ENABLE(); //使能GPIOF时钟
        __HAL_RCC_SPI5_CLK_ENABLE();  //使能SPI5时钟

        //PF7,8,9
        GPIO_Initure.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //复用推挽输出
        GPIO_Initure.Pull = GPIO_PULLUP;        //上拉
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //快速
        GPIO_Initure.Alternate = GPIO_AF5_SPI5; //复用为SPI5
        HAL_GPIO_Init(GPIOF, &GPIO_Initure);
    }
    if (hspi->Instance == SPI1)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE(); //使能GPIOA时钟
        __HAL_RCC_SPI1_CLK_ENABLE();  //使能SPI1时钟

        //PA5,6,7
        GPIO_Initure.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //复用推挽输出
        GPIO_Initure.Pull = GPIO_PULLUP;        //上拉
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //快速
        GPIO_Initure.Alternate = GPIO_AF5_SPI1; //复用为SPI1
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);
    }
    if (hspi->Instance == SPI2)
    {
        __HAL_RCC_GPIOB_CLK_ENABLE(); //使能GPIOB时钟
        __HAL_RCC_SPI2_CLK_ENABLE();  //使能SPI2时钟

        //PB13,14,15
        GPIO_Initure.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //复用推挽输出
        GPIO_Initure.Pull = GPIO_PULLUP;        //上拉
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //快速
        GPIO_Initure.Alternate = GPIO_AF5_SPI2; //复用为SPI1
        HAL_GPIO_Init(GPIOB, &GPIO_Initure);
    }
}

//SPI速度设置函数
//SPI速度=fAPB1/分频系数
//@ref SPI_BaudRate_Prescaler:SPI_BAUDRATEPRESCALER_2~SPI_BAUDRATEPRESCALER_2 256
//fAPB1时钟一般为45Mhz：
void SPI5_SetSpeed(u8 SPI_BaudRatePrescaler)
{
    assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler)); //判断有效性
    __HAL_SPI_DISABLE(&SPI5_Handler);                               //关闭SPI
    SPI5_Handler.Instance->CR1 &= 0XFFC7;                           //位3-5清零，用来设置波特率
    SPI5_Handler.Instance->CR1 |= SPI_BaudRatePrescaler;            //设置SPI速度
    __HAL_SPI_ENABLE(&SPI5_Handler);                                //使能SPI
}

u8 SPI5_ReadWriteByte(u8 TxData)
{
    u8 Rxdata;
    HAL_SPI_TransmitReceive(&SPI5_Handler, &TxData, &Rxdata, 1, 1000);
    return Rxdata; 
}

u8 SPI1_ReadWriteByte(u8 TxData)
{
    u8 Rxdata;
    HAL_SPI_TransmitReceive(&SPI1_Handler, &TxData, &Rxdata, 1, 1000);
    return Rxdata; 
}

void SPI5_MCU1_TEST(void)
{
    u16 Temp = 0;
     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET);
 
    SPI5_ReadWriteByte(0x90);
    SPI5_ReadWriteByte(0x00);
    SPI5_ReadWriteByte(0x00);
    SPI5_ReadWriteByte(0x00);
    Temp |= SPI5_ReadWriteByte(0xFF) << 8;
    Temp |= SPI5_ReadWriteByte(0xFF);
       HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_SET);
    printf("SPI5_TEST is :%x\r\n", Temp);
}

void SPI5_MCU2_TEST(void)
{
    u16 Temp = 0;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
    SPI5_ReadWriteByte(0x90);
    SPI5_ReadWriteByte(0x00);
    SPI5_ReadWriteByte(0x00);
    SPI5_ReadWriteByte(0x00);
    Temp |= SPI5_ReadWriteByte(0xFF) << 8;
    Temp |= SPI5_ReadWriteByte(0xFF);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
}

void SPI1_MCU1_TEST(void)
{
    u16 Temp = 0;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    SPI1_ReadWriteByte(0x90);
    SPI1_ReadWriteByte(0x00);
    SPI1_ReadWriteByte(0x00);
    SPI1_ReadWriteByte(0x00);
    Temp |= SPI1_ReadWriteByte(0xFF) << 8;
    Temp |= SPI1_ReadWriteByte(0xFF);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    printf("SPI1_TEST is :%x\r\n", Temp);
   // GPIO_Write(GPIOA,0xF);
}

int SPI2_MCU1_TEST(void)
{
  //1. write 0x22 to 0x11
  uint8_t tx[3]={0x0, 0x11, 0x22};
  uint8_t rx[3]={0};
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, sizeof(tx),1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  printf("spi str : %x\r\n",rx[0]);
  printf("spi str : %x\r\n",rx[1]);
  printf("spi str : %x\r\n",rx[2]);
  memset(rx,0,3);
  HAL_Delay(10);
  //2. send readcmd （read from 0x11）
  tx[0]=1;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, sizeof(tx),1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  printf("spi str : %x\r\n",rx[0]);
  printf("spi str : %x\r\n",rx[1]);
  printf("spi str : %x\r\n",rx[2]);
  memset(rx,0,3);
  HAL_Delay(5);
  //read value
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, 1,1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  printf("---------value 0x%x----\r\n\r\n\r\n",rx[0]);
  return rx[0];
}


int SPI2_MCU1_CONF_READ_TEST(uint8_t addr,uint8_t value)
{
  //1. write 0x22 to 0x11
  uint8_t tx[3]={0x0, addr, value};
  uint8_t rx[3]={0};
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
 // HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, sizeof(tx),1000);
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
 // printf("spi str : %x\r\n",rx[0]);
 // printf("spi str : %x\r\n",rx[1]);
 // printf("spi str : %x\r\n",rx[2]);
 // memset(rx,0,3);
 // HAL_Delay(10);
  //2. send readcmd （read from 0x11）
  tx[0]=1;
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, sizeof(tx),1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  printf("spi str : %x\r\n",rx[0]);
  printf("spi str : %x\r\n",rx[1]);
  printf("spi str : %x\r\n",rx[2]);
  memset(rx,0,3);
  HAL_Delay(5);
  //read value
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, 1,1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  printf("---------value 0x%x----\r\n\r\n\r\n",rx[0]);
  return rx[0];
}

void SPI2_MCU1_CONF_WRITE_TEST(uint8_t addr,uint8_t value)
{
  //1. write 0x22 to 0x11
  uint8_t tx[3]={0x0, addr, value};
  uint8_t rx[3]={0};
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_SPI_TransmitReceive(&SPI2_Handler, tx, rx, sizeof(tx),1000);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
 printf("spi str : %x\r\n",rx[0]);
 printf("spi str : %x\r\n",rx[1]);
 printf("spi str : %x\r\n",rx[2]);
 memset(rx,0,3);
 HAL_Delay(10);
}