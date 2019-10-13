const num = [4,1,-6,8,100,-20,54];
var temp = 0;

for(var i = 0; i < num.length; i++) {
	for(var j = i+1; j < num.length; j++) {
		if(num[i] > num[j]) {
			temp = num[j];
			num[j] = num[i];
			num[i] = temp;
        }
    }
}

console.table(num)