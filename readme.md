# Program
### Программа detTransp
Программа находит трнаспонированную матрицу или определитель матрицы, в зависимости от переданного параметра
Help программы:
```
Options:
  -h [ --help ]         Help screen
  --action arg          Находит трнаспонированную матрицу, если action=transp.
                        Находит определитель, если action=det
  --fileA arg           File name A
  --inputA              Input A
  --nA arg              Input n A
  --mA arg              Input m A
  ```
### Библиотека math
Библиотека math содержит две 
1. `double det(double** a, int na, int ma);`
2. `double** transp(double** a, int na, int ma, int &nr, int &mr);`

Первая служит для нахождения трнаспонированной матрицы, вторая для нахождения определителя матрицы.

## Результат тестов

**math:** ![example workflow](https://github.com/5pocplus/Program/actions/workflows/main.yml/badge.svg)
