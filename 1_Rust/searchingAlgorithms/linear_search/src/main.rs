fn main() {
    let data = [4,7,2,8,3,90,10,5];
    let search_for = 8;
    let result;
    // switch between two implementations of linear search
    let switch = 0;
    
    if switch == 1 {
        result = lin_search(& data, search_for);
    } else {
        result = lin_search_alt(& data, search_for);
    }
    // print out result
    if result == -1 {
        println!("Element not found");
    } else {
        println!("Element is at index {}", result);
    }
    
}

fn lin_search(input_arr: &[i32; 8] , search_elem: i32) -> i32 {
    let mut idx_pos = 0;
    for count in 0..input_arr.len() {                                           // Output of len() is of type usize --> i.e. count is of type usize
        if input_arr[count] == search_elem {
            idx_pos = count as i32;                                             // count has to be casted as type i32, since we have defined an output of type i32 in the lin_search function
            return idx_pos
        } else {
            idx_pos = -1
        }
    }
    idx_pos                             // in Rust, the last line of code is a return value, so if nothing is provided here, the compiler thinks that we are returning ().
}

fn lin_search_alt(input_arr: &[i32; 8], search_elem: i32) -> i32 {
    let mut idx_pos = -1;
    for (count,value) in input_arr.iter().enumerate() {
        if value == &search_elem {
            idx_pos = count as i32;
            return idx_pos
        }
    }
    idx_pos
}