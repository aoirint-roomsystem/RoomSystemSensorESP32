# RoomSystemSensorESP32

## Build
1. Copy template.env to .env and edit.
2. Execute `./update.sh /dev/ttyUSB0` (change `/dev/ttyUSB0` to your port).
    - To kill serial monitor (`screen` command), press `Ctrl+A K` and `y`.

### Requirements
- [Firebase ESP32 Client](https://github.com/mobizt/Firebase-ESP32)
- [EspSoftwareSerial](https://github.com/plerup/espsoftwareserial)
- [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini)

## .env
- Firebase Realtime Database Host URL
- Firebase Realtime Database Secret (Legacy)
- WiFi SSID
- WiFi Password
- Sound Volume [0, 30]

## Parts
- Illuminance sensor
  - NJL7202L-F3
    - [秋月電子通商](http://akizukidenshi.com/catalog/g/gI-08910/)
- Temperature sensor
  - LM61CIZ
    - [秋月電子通商](http://akizukidenshi.com/catalog/g/gI-11160/)
- ESP32-DevKitC

## Circuit
```
[5V]-[Long]Illumi Sensor[Short]-T--[PIN D32]
                                L-[200kΩ]--[GND]
```

```
(top view)

            (rounded)
           ___--^--___
[5V]-[Left]Temp Sensor[Right]-[GND]
             [Center]
                 L--[PIN D33]
```

```
[GND]---o [Aluminium pieces(electrode)] o---[D21 (PULLUP)]
```

```
Now Button

[GND]---o [Push Button] o---[D18 (PULLUP)]


Wait Button

[GND]---o [Push Button] o---[D19 (PULLUP)]
```
