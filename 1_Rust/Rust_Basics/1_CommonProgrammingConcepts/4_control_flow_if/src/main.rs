/* IF EXPRESSIONS
- if expression: run code depending on whether a condition is true
*/

fn main() {
    // If expression --> SYNTAX SIMILAR TO C
    let number = 9;
    if number > 8 {
        println!("Condition is true!")
    } else {
        println!("Condition is false")
    }

    /*
    --> using multiple conditions with else if. Example:
     */
    let number = 6;
    if number % 4 == 0 {
        println!("Number is divisible by 4");
    } else if number % 3 == 0 {                                 // this condition is true
        println!("Number is divisible by 3");
    } else if number % 2 == 0 {                                 // this is also true, but it is not run, since Rust only executes the block for the first true condition and once it finds one it doesn't check the rest. Similar to C.
        println!("Number is divisible by 2");
    } else {
        println!("Number is not divisible by 4, 3, or 2");
    }

    /* IF CONDITION --> LET STATEMENT
    --> assign a value to a variable depending on a condition
    Example:
    */
    let condition = false;
    let number = if condition {                                 // the variable will be bound to the value depending on the outcome of the if condition
        5
    } else {
        6
    };
    println!("number is = {}", number);
}
