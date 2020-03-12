fn main() {
    selfie_and_rot("pR\nKo");
    println!("Hello, world!");
}
//"pR....\nKo....\n....oK\n....Rp"
//"pR....\nKo....\n....oK\n....Rp"
fn rot(s: &str) -> String {
    let s1: Vec<&str> = s.split('\n').collect();
    let s2: Vec<String> = s1.iter().map(|a| a.chars().rev().collect::<String>()).rev().collect();
    let s3: String = s2.join("\n");

    s3
}

fn selfie_and_rot(s: &str) -> String {
    let index = s.find('\n').unwrap_or(0);
    let mut mask = String::from_utf8(vec![b'.';index]).unwrap();
    mask.push_str("\n");
    let mut s2 = s.replace("\n",mask.as_str());
    s2.push_str(String::from_utf8(vec![b'.';index]).unwrap().as_str());
    let mut s3 = s2.clone();
    s3.push_str("\n");
    s3.push_str(rot(s2.as_str()).as_str());
    println!("{:#?}",s3);
    s3
}

// first parameter: dots have to be replaced by function of one variable
fn oper(f: fn(&str) -> String, s: &str) -> String {
    f(s)
}

fn testing1(s: &str, exp: &str) -> () {
    assert_eq!(oper(rot, s), exp.to_string())
}

fn testing2(s: &str, exp: &str) -> () {
    assert_eq!(oper(selfie_and_rot, s), exp.to_string())
}

#[test]
fn basics_oper() {
    testing1("fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL",
             "LyfUVC\nGUFjWk\nABpfre\nJMmPrD\ntcVYqC\nooujif");
    testing1("rkKv\ncofM\nzXkh\nflCB", "BClf\nhkXz\nMfoc\nvKkr");

    testing2("xZBV\njsbS\nJcpN\nfVnP",
             "xZBV....\njsbS....\nJcpN....\nfVnP....\n....PnVf\n....NpcJ\n....Sbsj\n....VBZx");
    testing2("uLcq\nJkuL\nYirX\nnwMB",
             "uLcq....\nJkuL....\nYirX....\nnwMB....\n....BMwn\n....XriY\n....LukJ\n....qcLu");
}