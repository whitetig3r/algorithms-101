// module imports
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// declarations and definitions
let myInputArray = [];
let result = [];
let foundAtIndex;

// pushing args into array
process.argv.forEach( (val, index) => {
    if(index === 0 || index === 1) return;
    myInputArray.push(Number(val));
});

//get search term
console.log("Enter the search term: ");
rl.on('line', (answer) => {
    result = myInputArray.filter( (value,index) => {
        if (value === Number(answer)) {
            foundAtIndex = index;  // A small side-effect | remove if possible
        }
        return value === Number(answer);
    })
    rl.close();
}).on('close', () => {
    if(result.length === 0){
        console.log("Not Found in the suppplied array!");
    }
    else{
        console.log("Found the element: ",result[0]," at index:",foundAtIndex+1);
    }
});