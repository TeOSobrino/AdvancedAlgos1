use std::io;

fn main() {

    let mut a_str = String::new();
    io::stdin().read_line(&mut a_str).expect("read error");
    let mut a_iter = a_str.split_whitespace();

    let mut statue_num = a_iter.next()
    .unwrap_or(&"1").parse::<usize>().expect("parse error");

    let guard_range = a_iter.next()
    .unwrap_or(&"1").parse::<u32>().expect("parse error");

    let mut pos = String::new();
    io::stdin().read_line(&mut pos).expect("read error");
    let mut pos_iter = pos.split_whitespace();

    let mut guard_num = 0;
    let mut max_range = 0;

    while statue_num > 0 {
        let pos = pos_iter.next()
        .unwrap_or(&"1").parse::<u32>().expect("parse error");
        
        //A cada estátua, se ela não estiver no alcance de um guarda, colocamos 
        //um guarda na posicao range+pos, e assim só precisamos colocar o proximo guarda
        //em pos+2*range, pois o alcance do guarda eh [pos, 2*range+pos]
        if pos > max_range {
            guard_num += 1;
            max_range = pos + 2*guard_range;
        }
        statue_num -= 1;
    }

    println!("{guard_num}");



}
