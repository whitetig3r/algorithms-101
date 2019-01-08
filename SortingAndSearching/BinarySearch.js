// module imports
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

//recursive binary search
const binarySearch = (l, r, searchTerm) => {
    if(r>=l){
        let mid = l + Math.round((r-l)/2);
        if(myInputArray[mid] === searchTerm) return mid;
        else if (myInputArray[mid] > searchTerm){
            return binarySearch(l,mid-1,searchTerm);
        }
        else{
            return binarySearch(mid+1,r,searchTerm);
        }
    }
    return -1;
}

//iterative binary search
const binaryIterativeSearch = (l ,r ,searchTerm) => {
    while(r>=l){
        let mid = l + Math.round((r-l)/2);
        if(myInputArray[mid] === searchTerm) return mid;
        else if(myInputArray[mid] > searchTerm) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

// declarations and definitions
let myInputArray = [];
let foundAtIndex = -1;

// pushing args into array
process.argv.forEach((val, index) => {
    if (index === 0 || index === 1) return;
    myInputArray.push(Number(val));
});

// a requirement of binary search is a sorted array
myInputArray.sort((num1, num2) => (num1 - num2)); //using a comparator function to sort in ascending order

//get search term
console.log("Enter the search term: ");
rl.on('line', (answer) => {
    let arrayLength = myInputArray.length;
    foundAtIndex = binarySearch(0,arrayLength-1,Number(answer))
    //foundAtIndex = binaryIterativeSearch(0, arrayLength - 1, Number(answer))
    rl.close();
}).on('close', () => {
    if(foundAtIndex !== -1){
        console.log("Element found at index: ",foundAtIndex+1);
    }
    else{
        console.log("Element not found in supplied array!");
    }
});