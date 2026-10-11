# AI Documentation (AI-NOTES.md)

- **Prompt:** "Tolong bantu buatkan struktur dasar Doubly Linked List di C++ dengan operasi insert di tengah, delete node, serta forward dan backward traversal menggunakan pointer next dan prev."
- **AI membantu dalam:** Memberikan kerangka logika dasar pointer `next` dan `prev` saat melakukan operasi penyisipan dan penghapusan node.
- **Apa yang kami ubah/uji:** Menyesuaikan studi kasus menjadi rute stasiun kereta dan menguji skenario penghapusan node.

- Prompt: "Bagaimana cara tester menguji edge cases dan mensimulasikan bug pada fungsi deleteNode di Doubly Linked List C++?"
- AI helped us with: Menjelaskan bagian baris kode head->prev = nullptr yang perlu diuji dan cara kerja pembaruan pointer saat node pertama atau terakhir dihapus.
- What we changed/tested: Menerapkan uji coba Task 9 dengan sengaja menghilangkan pembaruan pointer prev pada head baru untuk melihat efek bug saat penelusuran mundur, lalu memperbaikinya sesuai panduan lab.
