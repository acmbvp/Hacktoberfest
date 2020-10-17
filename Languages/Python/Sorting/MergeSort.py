def MergeSort(array):
    if (len(array) > 1):
        #finding the middle
        middle = int(len(array)/2)
        #left half from array
        left = array[:middle]
        #right half from array
        right = array[middle:]

        MergeSort(left)
        MergeSort(right)

        i = j = k = 0

        #getting data from each temp array (left and right) and puting into original one
        while(i < len(left) and j < len(right)):
            if(left[i] < right[j]):
                array[k] = left[i]
                i+=1
            else:
                array[k] = right[j]
                j+=1
            k+=1

        # Checking if any element was left in the temp arrays
        while(i < len(left)):
            array[k] = left[i]
            i+=1
            k+=1

        while(j < len(right)):
            array[k] = right[j]
            j+=1
            k+=1


    return array


###TEST AREA

if __name__ == '__main__':
    test_list = [5, 2, 8, 10, 223, 1, 42, 25, 90, 15]
    sorted_list = MergeSort(test_list)
    print(sorted_list)
