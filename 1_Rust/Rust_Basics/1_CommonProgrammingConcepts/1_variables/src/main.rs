fn main() {
    let x = 5;
    println!("The value of x is: {}", x);
    // x = 6;                                   // This doesn't work, since variables are per default immutable

    let mut y = 5;                              // a mutable variable, which can be reassigned later
    println!("The value of y is: {}", y);
    y = 6;
    println!("The value of y is: {}", y);

/* Difference between variables and constants 

--> constants are also immutable by default --> not allowed to use mut
--> constants are declared using the const keyword, not let
--> constants can be declared in any scope, including the global scope
--> constants may be be set only to a constant expression, not to the result of a function call or any other value that could only be computed at runtime
--> valid for the entire time a program runs within the scope they are declared in
For example:
*/
const MAX_POINTS: u32 = 100_000;    

/* Shadowing 

--> declare new variable with same name as a previous variable
--> new variable shadows previous variable --> i.e. second variable's value appears when the variable is used
For example:
*/

let x = 5;
println!("The value of x is: {}", x);
let x = x + 1;                                  // new x shadows old x and takes value of 5 + 1 = 6
println!("The value of x is: {}", x);
let x = x * 2;                                  // new x shadows old x and takes value of 6 * 2 = 12
println!("The value of x is: {}", x);

/* Difference between shadowing (with the use of 'let') and mut:
--> effectively declaring and creating a new variable every time
--> therefore, the type of the variable can be changed whilst using the same name
For example:
*/
let spaces = "    ";                            // spaces is a string type
println!("spaces = {}", spaces);
let spaces = spaces.len();                      // spaces if a number type
println!("spaces = {}", spaces);
}
