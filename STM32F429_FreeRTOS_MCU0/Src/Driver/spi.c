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
    SPI5_Handler.Init.Mode = SPI_MODE_MASTER;                        //����SPI����ģʽ������Ϊ��ģʽ
    SPI5_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //����SPI�������˫�������ģʽ:SPI����Ϊ˫��ģʽ
    SPI5_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
    SPI5_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
    SPI5_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
    SPI5_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
    SPI5_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256; //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
    SPI5_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
    SPI5_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //�ر�TIģʽ
    SPI5_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //�ر�Ӳ��CRCУ��
    SPI5_Handler.Init.CRCPolynomial = 7;                             //CRCֵ����Ķ���ʽ
    HAL_SPI_Init(&SPI5_Handler);                                     //��ʼ��
    __HAL_SPI_ENABLE(&SPI5_Handler);
    //SPI5_ReadWriteByte(0Xff);                           //��������
}

void SPI1_Init(void)
{
    SPI1_CSPIN_MCU1_Init();
    SPI1_Handler.Instance = SPI1;                                    //SP1
    SPI1_Handler.Init.Mode = SPI_MODE_MASTER;                        //����SPI����ģʽ������Ϊ��ģʽ
    SPI1_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //����SPI�������˫�������ģʽ:SPI����Ϊ˫��ģʽ
    SPI1_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
    SPI1_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
    SPI1_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
    SPI1_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
    SPI1_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64; //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
    SPI1_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
    SPI1_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //�ر�TIģʽ
    SPI1_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //�ر�Ӳ��CRCУ��
    SPI1_Handler.Init.CRCPolynomial = 7;                             //CRCֵ����Ķ���ʽ
    HAL_SPI_Init(&SPI1_Handler);                                     //��ʼ��
    __HAL_SPI_ENABLE(&SPI1_Handler);
    SPI1_ReadWriteByte(0Xff);                           //��������
}

void SPI2_Init(void)
{
    SPI1_CSPIN_MCU1_Init();
    SPI2_Handler.Instance = SPI2;                                    //SP2
    SPI2_Handler.Init.Mode = SPI_MODE_MASTER;                        //����SPI����ģʽ������Ϊ��ģʽ
    SPI2_Handler.Init.Direction = SPI_DIRECTION_2LINES;              //����SPI�������˫�������ģʽ:SPI����Ϊ˫��ģʽ
    SPI2_Handler.Init.DataSize = SPI_DATASIZE_8BIT;                  //����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
    SPI2_Handler.Init.CLKPolarity = SPI_POLARITY_HIGH;               //����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
    SPI2_Handler.Init.CLKPhase = SPI_PHASE_2EDGE;                    //����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
    SPI2_Handler.Init.NSS = SPI_NSS_SOFT;                            //NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
    SPI2_Handler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
    SPI2_Handler.Init.FirstBit = SPI_FIRSTBIT_MSB;                   //ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
    SPI2_Handler.Init.TIMode = SPI_TIMODE_DISABLE;                   //�ر�TIģʽ
    SPI2_Handler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;   //�ر�Ӳ��CRCУ��
    SPI2_Handler.Init.CRCPolynomial = 7;                             //CRCֵ����Ķ���ʽ
    HAL_SPI_Init(&SPI2_Handler);                                     //��ʼ��
    __HAL_SPI_ENABLE(&SPI2_Handler);
   // SPI2_ReadWriteByte(0Xff);                           //��������
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
    GPIO_InitTypeDef GPIO_Initure;
    if (hspi->Instance == SPI5)
    {
        __HAL_RCC_GPIOF_CLK_ENABLE(); //ʹ��GPIOFʱ��
        __HAL_RCC_SPI5_CLK_ENABLE();  //ʹ��SPI5ʱ��

        //PF7,8,9
        GPIO_Initure.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //�����������
        GPIO_Initure.Pull = GPIO_PULLUP;        //����
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //����
        GPIO_Initure.Alternate = GPIO_AF5_SPI5; //����ΪSPI5
        HAL_GPIO_Init(GPIOF, &GPIO_Initure);
    }
    if (hspi->Instance == SPI1)
    {
        __HAL_RCC_GPIOA_CLK_ENABLE(); //ʹ��GPIOAʱ��
        __HAL_RCC_SPI1_CLK_ENABLE();  //ʹ��SPI1ʱ��

        //PA5,6,7
        GPIO_Initure.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //�����������
        GPIO_Initure.Pull = GPIO_PULLUP;        //����
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //����
        GPIO_Initure.Alternate = GPIO_AF5_SPI1; //����ΪSPI1
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);
    }
    if (hspi->Instance == SPI2)
    {
        __HAL_RCC_GPIOB_CLK_ENABLE(); //ʹ��GPIOBʱ��
        __HAL_RCC_SPI2_CLK_ENABLE();  //ʹ��SPI2ʱ��

        //PB13,14,15
        GPIO_Initure.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;    //�����������
        GPIO_Initure.Pull = GPIO_PULLUP;        //����
        GPIO_Initure.Speed = GPIO_SPEED_FAST;   //����
        GPIO_Initure.Alternate = GPIO_AF5_SPI2; //����ΪSPI1
        HAL_GPIO_Init(GPIOB, &GPIO_Initure);
    }
}

//SPI�ٶ����ú���
//SPI�ٶ�=fAPB1/��Ƶϵ��
//@ref SPI_BaudRate_Prescaler:SPI_BAUDRATEPRESCALER_2~SPI_BAUDRATEPRESCALER_2 256
//fAPB1ʱ��һ��Ϊ45Mhz��
void SPI5_SetSpeed(u8 SPI_BaudRatePrescaler)
{
    assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_BaudRatePrescaler)); //�ж���Ч��
    __HAL_SPI_DISABLE(&SPI5_Handler);                               //�ر�SPI
    SPI5_Handler.Instance->CR1 &= 0XFFC7;                           //λ3-5���㣬�������ò�����
    SPI5_Handler.Instance->CR1 |= SPI_BaudRatePrescaler;            //����SPI�ٶ�
    __HAL_SPI_ENABLE(&SPI5_Handler);                                //ʹ��SPI
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
  //2. send readcmd ��read from 0x11��
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
  //2. send readcmd ��read from 0x11��
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