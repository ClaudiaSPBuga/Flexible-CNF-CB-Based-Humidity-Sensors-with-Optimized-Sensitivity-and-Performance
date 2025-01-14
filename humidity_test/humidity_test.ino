//#include <Adafruit_BME280.h>
#include <Adafruit_ADS1X15.h>
#include <DHT.h>
/***********************************************************
 $$$$$$\   $$$$$$\  $$\   $$\ $$$$$$$$\ $$$$$$\  $$$$$$\  
$$  __$$\ $$  __$$\ $$$\  $$ |$$  _____|\_$$  _|$$  __$$\ 
$$ /  \__|$$ /  $$ |$$$$\ $$ |$$ |        $$ |  $$ /  \__|
$$ |      $$ |  $$ |$$ $$\$$ |$$$$$\      $$ |  $$ |$$$$\ 
$$ |      $$ |  $$ |$$ \$$$$ |$$  __|     $$ |  $$ |\_$$ |
$$ |  $$\ $$ |  $$ |$$ |\$$$ |$$ |        $$ |  $$ |  $$ |
\$$$$$$  | $$$$$$  |$$ | \$$ |$$ |      $$$$$$\ \$$$$$$  |
 \______/  \______/ \__|  \__|\__|      \______| \______/
**************************************************************/
//#define BME_TEMP // Comment to disbale
//#define BME_HUMD // Comment to disbale
//#define BME_PRES // Comment to disbale
#define DHT_HUMD // Comment to disbale
//#define DHT_TEMP // Comment to disbale
#define ADS_HUMD_CH0 // Comment to disbale
#define ADS_HUMD_CH1 // Comment to disbale
#define ADS_HUMD_CH2 // Comment to disbale
//#define ADS_HUMD_CH3 // Comment to disbale
/*************************************
$$$$$$$\  $$\      $$\ $$$$$$$$\       
$$  __$$\ $$$\    $$$ |$$  _____|      
$$ |  $$ |$$$$\  $$$$ |$$ |            
$$$$$$$\ |$$\$$\$$ $$ |$$$$$\          
$$  __$$\ $$ \$$$  $$ |$$  __|         
$$ |  $$ |$$ |\$  /$$ |$$ |            
$$$$$$$  |$$ | \_/ $$ |$$$$$$$$\       
\_______/ \__|     \__|\________|
*************************************/
/*
#define BME_TEMP_RATE_MS 1000
#define BME_HUMD_RATE_MS 1000
#define BME_PRES_RATE_MS 1000
*/// NOT IN USE
#define BME_RATE_MS 100 //Sampling time in miliseconds
/************************************
 $$$$$$\  $$$$$$$\   $$$$$$\  
$$  __$$\ $$  __$$\ $$  __$$\ 
$$ /  $$ |$$ |  $$ |$$ /  \__|
$$$$$$$$ |$$ |  $$ |$$ |      
$$  __$$ |$$ |  $$ |$$ |      
$$ |  $$ |$$ |  $$ |$$ |  $$\ 
$$ |  $$ |$$$$$$$  |\$$$$$$  |
\__|  \__|\_______/  \______/
***************************************/
/*
#define ADS_HUMD_RATE_MS 1000
*/// NOT IN USE
#define ADS_RATE_MS 100 //Sampling time in miliseconds+
#define ADS_GAIN GAIN_ONE //ADC Gain
#define ADS_BASE_RES_CH0 10000 //Fixed Resistence on channel 0 for resistance readout calulation
#define ADS_BASE_RES_CH1 10000 //Fixed Resistence on channel 0 for resistance readout calulation
#define ADS_BASE_RES_CH2 10000 //Fixed Resistence on channel 0 for resistance readout calulation
//#define ADS_BASE_RES_CH3 82000 //Fixed Resistence on channel 0 for resistance readout calulation
/**************************************
$$$$$$$\  $$\   $$\ $$$$$$$$\ 
$$  __$$\ $$ |  $$ |\__$$  __|
$$ |  $$ |$$ |  $$ |   $$ |   
$$ |  $$ |$$$$$$$$ |   $$ |   
$$ |  $$ |$$  __$$ |   $$ |   
$$ |  $$ |$$ |  $$ |   $$ |   
$$$$$$$  |$$ |  $$ |   $$ |   
\_______/ \__|  \__|   \__|
**********************************/
/*
#define DHT_TEMP_RATE_MS 1000
#define DHT_HUMD_RATE_MS 1000
*/// NOT IN USE
#define DHT_RATE_MS 100 //Sampling time in miliseconds
#define DHT_PIN 17 //Pin DTH is connected to for writing/reading operation
#define DHT_TYPE DHT22 //DTH model

/**************************************************************************************************************************
$$$$$$$$\ $$\   $$\ $$$$$$$\         $$$$$$\  $$$$$$$$\        $$$$$$\   $$$$$$\  $$\   $$\ $$$$$$$$\ $$$$$$\  $$$$$$\  
$$  _____|$$$\  $$ |$$  __$$\       $$  __$$\ $$  _____|      $$  __$$\ $$  __$$\ $$$\  $$ |$$  _____|\_$$  _|$$  __$$\ 
$$ |      $$$$\ $$ |$$ |  $$ |      $$ /  $$ |$$ |            $$ /  \__|$$ /  $$ |$$$$\ $$ |$$ |        $$ |  $$ /  \__|
$$$$$\    $$ $$\$$ |$$ |  $$ |      $$ |  $$ |$$$$$\          $$ |      $$ |  $$ |$$ $$\$$ |$$$$$\      $$ |  $$ |$$$$\ 
$$  __|   $$ \$$$$ |$$ |  $$ |      $$ |  $$ |$$  __|         $$ |      $$ |  $$ |$$ \$$$$ |$$  __|     $$ |  $$ |\_$$ |
$$ |      $$ |\$$$ |$$ |  $$ |      $$ |  $$ |$$ |            $$ |  $$\ $$ |  $$ |$$ |\$$$ |$$ |        $$ |  $$ |  $$ |
$$$$$$$$\ $$ | \$$ |$$$$$$$  |       $$$$$$  |$$ |            \$$$$$$  | $$$$$$  |$$ | \$$ |$$ |      $$$$$$\ \$$$$$$  |
\________|\__|  \__|\_______/        \______/ \__|             \______/  \______/ \__|  \__|\__|      \______| \______/
**************************************************************************************************************************/
/************************************************************
 $$$$$$\  $$\       $$$$$$\  $$$$$$$\   $$$$$$\  $$\       
$$  __$$\ $$ |     $$  __$$\ $$  __$$\ $$  __$$\ $$ |      
$$ /  \__|$$ |     $$ /  $$ |$$ |  $$ |$$ /  $$ |$$ |      
$$ |$$$$\ $$ |     $$ |  $$ |$$$$$$$\ |$$$$$$$$ |$$ |      
$$ |\_$$ |$$ |     $$ |  $$ |$$  __$$\ $$  __$$ |$$ |      
$$ |  $$ |$$ |     $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |      
\$$$$$$  |$$$$$$$$\ $$$$$$  |$$$$$$$  |$$ |  $$ |$$$$$$$$\ 
 \______/ \________|\______/ \_______/ \__|  \__|\________|
*************************************************************/
#if defined(BME_TEMP)||defined(BME_HUMD)||defined(BME_PRES)
Adafruit_BME280 bme;
unsigned long BME_previousTime = millis();
#endif
#if defined(DHT_HUMD)||defined(DHT_TEMP)
DHT dht(DHT_PIN, DHT_TYPE); 
unsigned long DHT_previousTime = millis();
#endif
#if defined(ADS_HUMD_CH0)||defined(ADS_HUMD_CH1)||defined(ADS_HUMD_CH2)||defined(ADS_HUMD_CH3)
Adafruit_ADS1115 ads;
unsigned long ADC_previousTime = millis();
#endif
unsigned long currentTime = millis();
/****************************************************************
 $$$$$$\  $$$$$$$$\ $$$$$$$$\ $$\   $$\ $$$$$$$\  
$$  __$$\ $$  _____|\__$$  __|$$ |  $$ |$$  __$$\ 
$$ /  \__|$$ |         $$ |   $$ |  $$ |$$ |  $$ |
\$$$$$$\  $$$$$\       $$ |   $$ |  $$ |$$$$$$$  |
 \____$$\ $$  __|      $$ |   $$ |  $$ |$$  ____/ 
$$\   $$ |$$ |         $$ |   $$ |  $$ |$$ |      
\$$$$$$  |$$$$$$$$\    $$ |   \$$$$$$  |$$ |      
 \______/ \________|   \__|    \______/ \__|
****************************************************************/
#if defined(BME_TEMP)||defined(BME_HUMD)||defined(BME_PRES)
int config_bme(void)
{
  int status;
  Serial.println("BME Configured!");
  status=bme.begin();  
  return 0;
}
#endif
#if defined(DHT_HUMD)||defined(DHT_TEMP)
int config_dht(void)
{
  Serial.println("DHT Configured!");
  dht.begin();
  return 0;
}
#endif
#if defined(ADS_HUMD_CH0)||defined(ADS_HUMD_CH1)||defined(ADS_HUMD_CH2)||defined(ADS_HUMD_CH3)
int config_ads(void)
{
  Serial.println("ADS Configured!");
  ads.setGain(ADS_GAIN);
  ads.begin();
  return 0;
}
#endif
void setup() 
{
  unsigned status;
  Serial.begin(9600);
#if defined(BME_TEMP)||defined(BME_HUMD)||defined(BME_PRES)
  status=config_bme();
#endif
#if defined(DHT_HUMD)||defined(DHT_TEMP)
  status=config_dht();
#endif
#if defined(ADS_HUMD_CH0)||defined(ADS_HUMD_CH1)||defined(ADS_HUMD_CH2)||defined(ADS_HUMD_CH3)
  status=config_ads();
#endif
}
/****************************************************************
$$\       $$$$$$\   $$$$$$\  $$$$$$$\  
$$ |     $$  __$$\ $$  __$$\ $$  __$$\ 
$$ |     $$ /  $$ |$$ /  $$ |$$ |  $$ |
$$ |     $$ |  $$ |$$ |  $$ |$$$$$$$  |
$$ |     $$ |  $$ |$$ |  $$ |$$  ____/ 
$$ |     $$ |  $$ |$$ |  $$ |$$ |      
$$$$$$$$\ $$$$$$  | $$$$$$  |$$ |      
\________|\______/  \______/ \__|
*****************************************************************/
#if defined(BME_TEMP)||defined(BME_HUMD)||defined(BME_PRES)
void bme_acquire(void)
{
  float bme_temp;
  float bme_humd;
  float bme_pres;
//#ifdef BME_TEMP
//  bme_temp = bme.readTemperature();
//  Serial.print("BME Temperature: ");
//  Serial.println(bme_temp);
//#endif
#ifdef BME_HUMD
//  bme_humd = bme.readHumidity();
//  Serial.print("BME Humidity: ");
//  Serial.print(bme_humd);
#endif
//#ifdef BME_PRES
//  bme_pres = bme.readPressure();
//  Serial.print("BME Pressure ");
//  Serial.println(bme_pres);
//#endif
  return;
}
#endif
#if defined(DHT_HUMD)||defined(DHT_TEMP)
void dht_acquire(void)
{
  float dht_humd;
  float dht_temp;
  #ifdef DHT_TEMP
  dht_temp = dht.readTemperature();
  //Serial.print("DHT Temperature: ");
  //Serial.println(dht_temp);
#endif
#ifdef DHT_HUMD
  dht_humd = dht.readHumidity();
  Serial.println(" ");
  Serial.print(" DHT Humidity: ");
  Serial.print(dht_humd);
#endif
  return;
}
#endif
#if defined(ADS_HUMD_CH0)||defined(ADS_HUMD_CH1)||defined(ADS_HUMD_CH2)||defined(ADS_HUMD_CH3)
void ads_convert_to_res(uint16_t raw_value, uint32_t base_res)
{
  float resistance;
  float volts;
  volts = ads.computeVolts(raw_value);
  //Serial.print("||ADC Converted Volts: ");
 // Serial.print(volts);
  resistance = (volts*base_res)/(5-volts);
  Serial.print(" ADC Converted Resistance: ");
  Serial.print(resistance);
}


void ads_acquire(void)
{
  uint16_t adc_raw;
#ifdef ADS_HUMD_CH0
  adc_raw = ads.readADC_SingleEnded(0);
//  Serial.print("ADS Raw Value Ch 0:");
//  Serial.print(adc_raw);
  ads_convert_to_res(adc_raw,ADS_BASE_RES_CH0);
 

#endif
#ifdef ADS_HUMD_CH1
  adc_raw = ads.readADC_SingleEnded(1);
  //Serial.print("ADS Raw Value Ch 1:");
  //Serial.print(adc_raw);
  ads_convert_to_res(adc_raw,ADS_BASE_RES_CH1);
#endif
#ifdef ADS_HUMD_CH2
  adc_raw = ads.readADC_SingleEnded(2);
  //Serial.print("ADS Raw Value Ch 2:");
  //Serial.print(adc_raw);
  ads_convert_to_res(adc_raw,ADS_BASE_RES_CH2);
  
#endif
#ifdef ADS_HUMD_CH3
  adc_raw = ads.readADC_SingleEnded(3);
  //Serial.print("ADS Raw Value Ch 3:");
  //Serial.print(adc_raw);
 // ads_convert_to_res(adc_raw,ADS_BASE_RES_CH3);
#endif
  return;
}
#endif
void loop()
{
  currentTime = millis();
#if defined(BME_TEMP)||defined(BME_HUMD)||defined(BME_PRES)
  if((currentTime-BME_previousTime)>BME_RATE_MS)
  {
    BME_previousTime = currentTime;
    bme_acquire();
  }
#endif
#if defined(DHT_HUMD)||defined(DHT_TEMP)
  if((currentTime-DHT_previousTime)>DHT_RATE_MS)
  {
    DHT_previousTime = currentTime;
    dht_acquire();
  }
#endif
#if defined(ADS_HUMD_CH0)||defined(ADS_HUMD_CH1)||defined(ADS_HUMD_CH2)||defined(ADS_HUMD_CH3)
  if((currentTime-ADC_previousTime)>ADS_RATE_MS)
  {
    ADC_previousTime = currentTime;
    ads_acquire();
  }
#endif
}
