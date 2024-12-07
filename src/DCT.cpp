#include "DCT.h"

std::minstd_rand Treap::generator;

Treap::~Treap() {
    clear(root);
}

bool Treap::contains(int key) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);

    bool result = equal != nullptr; // Ïğîâåğÿåì, ñóùåñòâóåò ëè óçåë ñ äàííûì êëş÷îì
    root = merge(merge(less, equal), greater); // Âîññòàíàâëèâàåì äåğåâî
    return result; // Âîçâğàùàåì ğåçóëüòàò
}

void Treap::insert(int key) {
    Node* less = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater); // Ğàçäåëÿåì ïî êëş÷ó
    root = merge(merge(less, new Node(key)), greater); // Îáúåäèíÿåì ñ íîâûì óçëîì
}

void Treap::erase(int key) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);

    root = merge(less, greater); // Îáúåäèíÿåì îñòàâøèåñÿ óçëû
    delete equal; // Îñâîáîæäàåì ïàìÿòü äëÿ óçëà
}

void Treap::clear(Node* node) {
    if (!node) return; // Åñëè óçåë ïóñò, âûõîäèì
    clear(node->l); // Ğåêóğñèâíî î÷èùàåì ëåâîå ïîääåğåâî
    clear(node->r); // Ğåêóğñèâíî î÷èùàåì ïğàâîå ïîääåğåâî
    delete node; // Îñâîáîæäàåì ïàìÿòü
}

Treap::Node* Treap::merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b; // Âîçâğàùàåò íåïóñòîå ïîääåğåâî

    if (a->priority > b->priority) { // Ñğàâíèâàåì ïğèîğèòåòû
        a->r = merge(a->r, b); // Îáúåäèíÿåì ïğàâîå ïîääåğåâî
        return a; // Âîçâğàùàåì êîğåíü ïåğâîãî ïîääåğåâà
    }
    else {
        b->l = merge(a, b->l); // Îáúåäèíÿåì ëåâîå ïîääåğåâî
        return b; // Âîçâğàùàåì êîğåíü âòîğîãî ïîääåğåâà
    }
}

void Treap::split(Node* n, int key, Node*& a, Node*& b) {
    if (!n) {
        a = b = nullptr; // Åñëè óçåë ïóñò, âîçâğàùàåì nullptr
        return;
    }
    if (n->key < key) { // Åñëè êëş÷ óçëà ìåíüøå çàäàííîãî
        split(n->r, key, n->r, b); // Ğåêóğñèâíî ğàçäåëÿåì ïğàâîå ïîääåğåâî
        a = n; // Óñòàíàâëèâàåì ëåâóş ÷àñòü
    }
    else {
        split(n->l, key, a, n->l); // Ğåêóğñèâíî ğàçäåëÿåì ëåâîå ïîääåğåâî
        b = n; // Óñòàíàâëèâàåì ïğàâóş ÷àñòü
    }
}

// Ìåòîä äëÿ íàõîæäåíèÿ ïåğâîãî ÷èñëà, íå ìåíüøåãî x
int Treap::lower_bound(int x) {
    Node* current = root;
    Node* answer = nullptr;

    while (current) {
        if (current->key < x) { // Åñëè òåêóùèé óçåë ìåíüøå x, èäåì âïğàâî
            current = current->r;
        }
        else { // Èíà÷å, ñîõğàíÿåì óçåë è èäåì âëåâî
            answer = current;
            current = current->l;
        }
    }
    return answer ? answer->key : -1; // Âîçâğàùàåì íàéäåííûé îòâåò èëè -1, åñëè ıëåìåíò íå íàéäåí
}

// Ìåòîä äëÿ ïîäñ÷åòà êîëè÷åñòâà ÷èñåë â äèàïàçîíå [l, r]
int Treap::count_in_range(int l, int r) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, r + 1, less, greater); // Ğàçäåëÿåì ïî r
    split(less, l, less, equal); // Ğàçäåëÿåì ïî l

    int count = count_nodes(equal); // Ïîäñ÷èòûâàåì êîëè÷åñòâî óçëîâ â ïğîìåæóòêå
    root = merge(merge(less, equal), greater); // Âîññòàíîâëåíèå äåğåâà
    return count;
}

// Ìåòîä äëÿ ïîäñ÷åòà óçëîâ â ïîääåğåâå
int Treap::count_nodes(Node* node) {
    if (!node) return 0;
    return 1 + count_nodes(node->l) + count_nodes(node->r);
}