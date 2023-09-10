use std::io;

//macro para ler n tipos da entrada e retornar uma tupla os contendo
macro_rules! parse_line {
    ($($t: ty),+) => ({
        let mut a_str = String::new();
        io::stdin().read_line(&mut a_str).expect("read error");
        let mut a_iter = a_str.split_whitespace();
        (
            $(
            a_iter.next().unwrap().parse::<$t>().expect("parse error"),
            )+
        )
    })
}
fn main() {
    let mut vec: Vec<(i32, i32)> = Vec::new(); 

    let mut max_lecture = String::new();
    io::stdin().read_line(&mut max_lecture).expect(" ");
    let mut max_lecture: i32 = max_lecture.trim().parse().expect("Not an integer");

    while max_lecture > 0 {
        
        //lemos uma tupla de (inicio, fim)
        let (start_time, finish_time): (i32, i32) = parse_line!(i32, i32);
        vec.push((start_time, finish_time));

        max_lecture -= 1;
    }

    //ordenamos fazendo uso de uma funcao (acessar o segundo elemento da tupla)
    vec.sort_by_key(|k| k.1);
    let mut earliest_finish = vec[0].1;
    let mut lecture_num = 1;
    for i in vec {
        if i.0 >= earliest_finish {
            lecture_num += 1;
            earliest_finish = i.1;
        }        
    }

    println!("{lecture_num}");
}
