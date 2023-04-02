/**
 *
 * @license MIT License
 *
 * Copyright (c) 2022 lewis he
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file      BAM423_Accelerometer.ino
 * @author    Lewis He (lewishe@outlook.com)
 * @date      2022-03-31
 *
 */
#include <Wire.h>
#include <SPI.h>
#include <Arduino.h>
#include "SensorBMA423.hpp"

// lilygo t-watch pin
#define I2C_SDA                     21
#define I2C_SCL                     22
#define BOARD_ACCE_IRQ              39

SensorBMA423 accel;
uint32_t lastMillis;

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    pinMode(BOARD_ACCE_IRQ, INPUT);

    if (!accel.begin(Wire, BMA423_SLAVE_ADDRESS, I2C_SDA, I2C_SCL)) {
        Serial.println("Failed to find BMA423 - check your wiring!");
        while (1) {
            delay(1000);
        }
    }
    Serial.println("Init BAM423 Sensor success!");

    //Default 4G ,200HZ
    accel.configAccelerometer();

    accel.enableAccelerometer();
}


void loop()
{
    int16_t x, y, z;
    accel.getAccelerometer(x, y, z);
    Serial.print("X:");
    Serial.print(x); Serial.print(" ");
    Serial.print("Y:");
    Serial.print(y); Serial.print(" ");
    Serial.print("Z:");
    Serial.print(z);
    Serial.println();

    delay(50);
}


