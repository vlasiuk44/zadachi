import csv
import os
otbor = ['GH', 'CE', 'PL', 'CBM', 'GT', 'AA']
niche = {}  # словарь отобраных бактерий с нишами
items = []  # массив всех файлов, с которыми взаимодействуем
vectors = []  # все векторы
vectors2_new = []
vectors2 = []
vectors_dict = []  # массив всех 560 бактерий, ключ - бактерия, значение - количество
enzymes = {}  # ключ - фермент, значения - все бактерии, в которых он есть

with open('niche2.csv') as File2:
    reader = csv.reader(File2, delimiter=';', quotechar=',',
                        quoting=csv.QUOTE_MINIMAL)
    for row in reader:
        niche[row[0]] = row[1]  # {'GCF_000064305.2': 'aquatic', 'GCF_000240075.2': 'aquatic', 'GCF_000252125.1': 'aquatic'...}

folder = 'C:/PyProj/pythonProject4/inp'
for subdir, dirs, files in os.walk(folder):
    for item in os.listdir(folder):  # перебор всех файлов
        if 'sum' in item:  # отбираем нужные файлы

            bac = 'inp/' + item  # строка - путь файла
            with open(bac) as File:  # открыть файл
                if os.stat(bac).st_size == 0: continue  # файл пустой
                items.append(item)  # добавляем в массив названия файлов
                dict = {}  # ключ - фермент, значение - его количество в бактерии
                reader = csv.reader(File, delimiter=',', quotechar=',',
                                    quoting=csv.QUOTE_MINIMAL)
                for row in reader:

                    for k in [x.strip() for y in row[0].split()[5].split('-') for x in
                              y.split(';')]:  # строка с ферментами, разбитая в массив
                        if k == 'pattern': continue

                        if '_' in k: k = str(k[:k.find('_')])  # игнорируем все _

                        if k not in enzymes.keys():
                            enzymes[k] = [item]  # добавляем ферменты
                        else:
                            if item not in enzymes[k]:
                                enzymes[k].append(item)  # добавляем бактерии
                        if k not in dict:
                            dict[k] = 1  # создаем фермент
                        else:
                            dict[k] += 1  # считаем кол-во ферментов
                        dict_new = {'GH':0, 'CE':0, 'PL':0, 'CBM':0, 'GT':0, 'AA':0}  # словарь для подсчета ненулевых ферментов
                        for h in dict.keys():
                            if h == 'susC' or h == 'susD' or h == 'unk': continue
                            for char in h:
                                if char.isdigit():
                                    h = h[:h.index(char)]
                                    # print(h)
                                    break
                            if h not in dict_new:
                                dict_new[h] = 1
                            else:
                                dict_new[h] += 1

            vectors_dict.append(dict)
            vectors.append(list(dict_new.values()))

for i in range(len(vectors)):
    if items[i][:15] in list(niche.keys()) and niche[items[i][:15]]=='freshwater':

        print(vectors[i],end=',\n')

print(list(dict_new.keys()))


