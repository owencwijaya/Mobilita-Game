/**
 * @brief Mengembalikan banyak baris efektif BooleanMatrix \c b.
 * @param b BooleanMatrix instance.
 */
#define rows(b) (b).rowEff
/**
 * @brief Mengembalikan banyak kolom efektif BooleanMatrix \c b.
 * @param b BooleanMatrix instance.
 */
#define cols(b) (b).colEff
/**
 * @brief Mengembalikan elemen matriks pada index (i, j).
 * @param b Sebuah matriks.
 * @param i Index baris elemen yang akan diambil.
 * @param j Index kolom elemen yang akan diambil.
 */
#define elem(b, i, j) (b).contents[i][j]

/**
 * @brief Mengembalikan panjang GameMap \c m.
 * @param m GameMap instance.
 */
#define mapLength(m) (m).hSize
/**
 * @brief Mengembalikan lebar GameMap \c m.
 * @param m GameMap instance.
 */
#define mapWidth(m) (m).vSize
/**
 * @private
 * @brief Mengembalikan matriks adjacency dari map \c m.
 * @see BooleanMatrix
 * @param m GameMap instance
 */
#define adjMatrix(m) (m)._adjacency
/**
 * @private
 * @brief Mengembalikan list lokasi yang ada pada \c m.
 * @see LocationList
 * @param m GameMap instance
 */
#define locList(m) (m)._locations
/**
 * @private
 * @brief Mengembalikan matriks lokasi dari map \c m.
 * ! Hanya digunakan untuk menampilkan output map.
 * @see LocationMatrix
 * @param m GameMap instance
 */
#define locMatrix(m) (m)._locationMatrix

/**
 * @brief Mengambil value dari sebuah ItemListNode.
 * @param node ItemListNode instance.
 */
#define value(node) (node).value
/**
 * @brief Mengambil pointer ke next node dari sebuah ItemListNode.
 * @param node ItemListNode instance.
 */
#define next(node) (node).next

/**
 * @brief Kapasitas maksimum ItemStack.
 */
#define ITEM_STACK_MAX_CAPACITY 100
/**
 * @brief Mengambil indeks teratas stack s.
 * @param s ItemStack instance.
 */
#define topIndex(s) (s).topIndex
/**
 * @brief Mengambil Item teratas pada stack s.
 * @param s ItemStack instance.
 */
#define top(s) (s).buffer[(s).topIndex]
/**
 * @brief Mengambil kapasitas stack s.
 * @param s ItemStack instance.
 */
#define capacity(s) (s).capacity

/**
 * @brief Mengambil indeks head pada antrian q.
 * @param q ItemQueue instance.
 */
#define headIndex(q) (q).headIndex
/**
 * @brief Mengambil indeks tail pada antrian q.
 * @param q ItemQueue instance.
 */
#define tailIndex(q) (q).tailIndex
/**
 * @brief Mengambil head Item pada antrian q.
 * @param q ItemQueue instance.
 */
#define head(q) (q).buffer[(q).headIndex]
/**
 * @brief Mengambil tail Item pada antrian q.
 * @param q ItemQueue instance.
 */
#define tail(q) (q).buffer[(q).tailIndex]

/**
 * @brief Mengambil lokasi pick up item.
 * @param item Item instance.
 */
#define pickUpLoc(item) (item).pickUpLocation
/**
 * @brief Mengambil lokasi drop off item.
 * @param item Item instance.
 */
#define dropOffLoc(item) (item).dropOffLocation
/**
 * @brief Mengambil tipe item.
 * @param item Item instance.
 */
#define itemType(item) (item).type
/**
 * @brief Mengambil waktu hangus item.
 * @param item Item instance.
 */
#define perishTime(item) (item).perishTime
/**
 * @brief Mengambil waktu hangus item sebagai referensi
 * @param item Item instance.
 */
#define perishTimeReference(item) (item).perishTimeReference
/**
 * @brief Mengambil waktu order item.
 * @param item Item instance.
 */
#define orderTime(item) (item).orderTime

/**
 * @brief Mengambil absis dari suatu titik.
 * @param p Point instance.
 */
#define x(p) (p).x
/**
 * @brief Mengambil ordinat dari suatu titik.
 * @param p Point instance.
 */
#define y(p) (p).y

/**
 * @brief Mengambil id dari suatu data.
 * @param l Suatu data.
 */
#define id(l) (l).id
/**
 * @brief Mengambil simbol lokasi.
 * @param l Location instance.
 */
#define symbol(l) (l).symbol
/**
 * @brief Mengambil koordinat lokasi.
 * @param l Location instance.
 */
#define coord(l) (l).coordinate

/**
 * @brief Mengambil banyak elemen list.
 * @param l LocationList instance.
 */
#define neff(l) (l).nEff
/**
 * @brief Mengambil memory list.
 * @param l LocationList instance.
 */
#define buffer(l) (l).buffer
/**
 * @brief Mengambil elemen list pada indeks tertentu.
 * @param l LocationList instance.
 * @param i Indeks elemen yang akan diambil.
 */
#define lElem(l, i) (l).buffer[i]

/**
 * @brief Mengambil property price dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define price(g) (g).price
/**
 * @brief Mengambil property name dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define name(g) (g).name
