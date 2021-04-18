# Read coredumps on esp32

## Coredumps printed on uart
* On menuconfig set "uart mode" and reserve 1024 bytes of ram.
* Copy coredump printed on monitor serial in a txt file.
* Run:
```python
python C:/esp41/esp-idf/components/espcoredump/espcoredump.py info_corefile -t b64 -c coredump_from_uart.txt build/coredump.elf
```
## Coredumps printed on flash
* On menuconfig set "flash mode" and reserve 1024 bytes of ram.
* Dumps automatilly will saved in flash.
### Method 1
```python
python C:/esp41/esp-idf/components/espcoredump/espcoredump.py -p COM18 info_corefile build/coredump.elf
```
### Method 2
* Read manually coredump partition, this will generate a txt file that contains coredump text:
```python
python C:\esp41\esp-idf\components\partition_table\parttool.py read_partition  --partition-name=coredump --output "coredump_from_flash.txt"
```
* Run:
```python
python C:/esp41/esp-idf/components/espcoredump/espcoredump.py info_corefile -t raw -c coredump_from_flash.txt build/coredump.elf
```

Note: Reserve 1024 bytes for coredump runtime purposses. To avoid extra ram comsuption in tasks or interrupts.