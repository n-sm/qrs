### Basado en Cormen 2.3.1 merge sort algorith

          
def merge_sort(lista):
    length = len(lista)
    if length > 1:
        medio = length // 2
        left  = lista[0:medio]
        right = lista[medio:]
        merge_sort(left)
        merge_sort(right)
        left.append(float('inf'))
        right.append(float('inf'))
        i,j = 0, 0
        while (i < medio) or (j < length - medio):
            if i < medio and left[i] <= right[j]:
                print("i + j es %s + %s = %s" % (i, j, i + j))
                lista[i + j] = left[i]
                i += 1
            else:
                print("i + j es %s + %s = %s" % (i, j, i + j))
                lista[i + j] = right[j]
                j += 1



## Lo que sigue se parece mejor al ejemplo de Cormen, pero la version
## anterior parece mas concisa.

def mergeSortedLists(list1, list2):
    length = len(list1) + len(list2)
    left = list1[:]
    right = list2[:]
    left.append(float('inf'))
    right.append(float('inf'))
    i = 0
    j = 0
    out = []
    #while(left[i] < float('inf') or right[j] < float('inf')):
    for k in range(length):
        if left[i] <= right[j]:
            out.append(left[i])
            i += 1
        else:
            out.append(right[j])
            j += 1
    return out

def mergeSort(lista, desde=None, hasta=None):
    if len(lista) < 2: return lista
    if desde is None: desde = 0
    if hasta is None: hasta = len(lista)
    #if not desde < hasta: return lista
    medio = (desde + hasta) // 2
    mitad1 = mergeSort(lista[desde:medio])
    mitad2 = mergeSort(lista[medio:hasta])
    mitades = mergeSortedLists(mitad1, mitad2)
    return lista[:desde] + mitades + lista[hasta:]
