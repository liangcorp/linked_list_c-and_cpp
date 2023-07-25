struct Node<T: std::fmt::Debug + std::marker::Copy> {
    element: T,
    next: Box<Option<Node<T>>>,
}
struct LinktedList<T: std::fmt::Debug + std::marker::Copy> {
    head: Box<Option<Node<T>>>,
}

impl<T: std::fmt::Debug + std::marker::Copy> LinktedList<T> {
    // TODO: linked list methods
}

fn main() {

}
