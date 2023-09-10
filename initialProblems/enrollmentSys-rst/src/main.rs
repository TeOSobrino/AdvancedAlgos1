use std::{collections::HashMap, io, vec};

fn main(){

    let mut enrollment_sys: HashMap<i32, i32> = HashMap::new();
    let mut course_id: String = String::new();
    io::stdin().read_line(&mut course_id).expect(" ");
    let mut course_id: i32 = course_id.trim().parse().expect("Expected an integer");
    let course_num = course_id;
    let mut vec: Vec<i32> = vec![0; (course_num) as usize];
    

    while course_id > 0 {

        let mut student_num = String::new();
        io::stdin().read_line(&mut student_num).expect(" ");
        let mut student_num: i32 = student_num.trim().parse().expect("Not an integer");

        while student_num > 0{
            let mut student_id = String::new();
            io::stdin().read_line(&mut student_id).expect(" ");
            let student_id: i32 = student_id.trim().parse().expect("Not an integer");
            
            let idd = enrollment_sys.get(&student_id);
            let enrolled_id = match idd {
                None => -2,
                Some(x) => *x, 
            };


            if enrolled_id == -2 {
                enrollment_sys.insert(student_id, course_id);
                //println!("key not yet added; key: {student_id}, value: {}", enrollment_sys[&student_id]);
            }

            else{
                if  enrolled_id != course_id {
                    *enrollment_sys.entry(student_id).or_insert(-1) = -1;
                    //println!("too many courses, key removed!");
                }
            }
            student_num -= 1;
        }
        course_id -= 1;
    }

    for (_key, val) in enrollment_sys.into_iter(){
        if val > 0 {
            vec[(course_num - val) as usize] += 1;
            // println!("{val}");
        }
    }
    
    

    for val in vec { print!("{val} ")}

}
