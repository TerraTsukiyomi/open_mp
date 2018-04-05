# Openmp tasks
Реализованные задачки по OpenMP
(VS -> кластер)

## VS

1. Создать пустой с++ проект в VS;
2. К проекту в VS, подключить библеотеку OpenMP
3. После написания с++ файла **скопировать** сохранить, закрыть

## Кластер *(консоль)*

1. **mkdir openmptasks** 

      *(создаём директорию/папку openmptasks)*

2. **mcedit example.c**

      *(создаём файл расширением .с, 
      сразу выплывет окно реадактирование содержмого этого файла, 
      **вставляем** ранее скопированый код, 
      **f2** - сохранить, 
      **f10** - закрыть)*

3. **gcc example.c -o example.bin -lm -fopenmp**

      *(создаём бинарник для **С**-шного файла, 
      **-o** - необязателен, 
      **-lm** - подключаем математическую библиотеку,
      **-fopenmp** -без него кластер не будет видеть бинарник.
      Создать бинарник для **С++**-шного файла можно с помощью аналогичной 
      команды: g++ example.c -o example.bin -fopenmp )*

4. **mcedit example.pbs**

      *(cоздаём скрипт для **С**-шного файла,
      или можно скопировать с существующего
      командой: cp example_tot_kotoriy_kopiruen.pbs example.pbs )*

5. **qsub example.pbs** 

      *(Выполняем скрипт, выдаётся сообщение примерно такое **22348.cluster** )*

6. **ls**

      *(Cмотрим, что у нас в дериктории. 
      Ищими файлы вида: **example.o22348**, **example.e22348**,
      у меня, среди прочих уже ненужных, их есть только два.)*

      *Выбераем файл напрмер **example.o22348** и кампелируем командой:*

7. **cat example.o22348**

      *(Кампелируем файл example.o22348)*

      
Любуемся выполнением программы на кластере :D


****
***
****
# Пример скрипта (файла example.pbs) для **С**-шного файла

#!/bin/sh

#PBS -d /home/student5/lugacheva/lab5

#PBS -l nodes=1:ppn=2,walltime=00:30:00

#PBS -N example

echo "File containing nodes:"

echo $PBS_NODEFILE

echo "Nodes for computing:"

cat $PBS_NODEFILE

echo "Start date: `date`"

nohup ./example.bin,

echo " End date: `date`"


# Пример скрипта (файла example.pbs) для **С++**-шного файла

#!/bin/bash

#PBS -d /home/student5/lugacheva/lab5

#PBS -l nodes=1:ppn=2,walltime=00:30:00

#PBS -N example

#PBS -m e

#PBS -V

./example.bin

# Заметка

Слово date должен быть в вот таких кавычках
` 
