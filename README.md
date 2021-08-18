# stm32_bootloader_library
Bootloader library and firmware update tool for stm32f4xx series controllers.

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#CLI">CLI tool for updating firmware</a></li>
    <li><a href="#CLI tool for updating firmware">Usage</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>




<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* Install the [Stlink utility and drivers](https://github.com/SaheblalBagwan/stlink-utility-and-drivers) and update the installation path to environment variables <b>C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility</b>.
* Ensure the bootloader binary and test application binaries are available at <b>root/cli-Tool/binaries</b>

### Installation

* [Stlink utillity and drivers](https://github.com/SaheblalBagwan/stlink-utility-and-drivers)


<!-- CLI -->
## CLI tool for updating firmware
1. Connect the device to the PC and note down the COM port from the device manager. 
2. Open the command line from the project root folder and run the below command
  ```` sh
  stm32UpdateTool-win.exe <COMxx>
  ```` 
3. Use the below commands for flashing teh bootloader and application.
  ```` 
     1. clear                           // clear screen
     2. device info                     // Print Device info
     3. device reset                    // Reset/Reboot Device info
     4. flash all <application.bin>     // flash bootloader+application
     5. flash bootloader                // flash bootloader
     6. flash app <application.bin>     // flash application
     7. flash erase_all                 // Erase chip
     8. flash erase_sector <sector_num> // Erase a sector
     9. logs enable                     // Enable device logs
    10. logs disable                    // Disable device logs
    11. help                            // Show supported
  ```` 
  
  <!-- Custom Application example -->
## Custom Application Example
After successfull device registeration the certificates are stored in the respective thing folders at <b>root/certificates/thingID</b> 


