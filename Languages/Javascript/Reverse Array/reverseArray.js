function ReverseArray(arrayPlace) {
    let a = arrayPlace.length - 1;
    let b = [];
    let x = 0;
    for (a; a >= 0; a--) {
      b[x] = arrayPlace[a];
      x++;
    }
    return b;
  }

  console.log(ReverseArray([1,2,3,4,5,6]))
  
  function ReverseArrayInPlace(arrayPlace) {
    let a = arrayPlace.length - 1;
    let x = a;
    for (let i = 0; i <= a; i++) {
      arrayPlace.push(arrayPlace[x]);
      arrayPlace.splice(x, 1);
      x--;
    }
    return arrayPlace;
  }

  console.log(ReverseArrayInPlace([1, 2, 3, 4, 5, 6]));
  
  