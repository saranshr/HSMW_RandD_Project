/* LOOPS
--> run code more than once (repeatedly)
--> Three kinds of loops:
    - loop
    - while
    - for
*/
fn main() {
    /* LOOP
    - loop keyword executes a block of code over and over again until explicitly told to stop
    Example:
    */
    loop {
        println!("again!");                          // infinite loop
        break;                                       // stops the loop after the first run
    }

    /* RETURNING VALUES FROM LOOP
    - one use case is for retrying an operation you know might fail, such as checking whether a thread has completed its job
    - you might want to return a value
    Example:
     */
    let mut counter = 0;
    let result = loop {
        println!("{}", counter);
        counter += 1;
        if counter == 10 {
            println!("before break");
            break counter * 2;                       // break can also return a value --> this is assigned to the variable result (the let statement)
        }
    };
    println!("The result is {}", result);

    /* WHILE --> Similar to C
    - while a condition is true, the loop runs
    - when the condition ceases being true, the program calls break (same as loop --> if --> else --> break)
    Example:
    */
    let mut num = 3;
    while num != 0 {
        println!("{}", num);
        num -= 1;
    }
    println!("Go!");

    /* FOR --> Similar to Python and fundamentally also C
    */
    let a = [1,2,3,4,5];
    for element in a.iter() {
        println!("The value is: {}", element);
    }
    for number in (1..4).rev() {
        println!("{}", number);
    }
    println!("Go!");

    let mut index = 0;                                      // this is the same as the for loop above, but the code is much more complicated: we
    while index < a.len() {                                 // need to use an extra variable as a counter and update it within the loop
        println!("the value is: {}", a[index]);             // moreover, it's also slower, since the complier adds the runtime code to perform the
        index += 1;                                         // conditional check on every element on every iteration through the loop
    }
}
