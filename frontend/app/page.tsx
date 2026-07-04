"use client";

import { useEffect, useMemo, useState } from "react";

import Sidebar from "@/components/Sidebar";
import Navbar from "@/components/Navbar";
import DashboardCards from "@/components/DashboardCards";
import BooksTable from "@/components/BooksTable";
import SearchBar from "@/components/SearchBar";
import AddBookModal from "@/components/AddBookModal";

import { books as initialBooks } from "@/data/books";
import { Book } from "@/types/book";

export default function Home() {

  const [books, setBooks] = useState<Book[]>(() => {

    if (typeof window !== "undefined") {

      const savedBooks = localStorage.getItem("books");

      if (savedBooks) {

        return JSON.parse(savedBooks);

      }

    }

    return initialBooks;

  });

  const [search, setSearch] = useState("");

  const [editBook, setEditBook] = useState<Book | null>(null);

  useEffect(() => {

    localStorage.setItem(
      "books",
      JSON.stringify(books)
    );

  }, [books]);

  const saveBook = (book: Book) => {

    const exists = books.some((b) => b.id === book.id);

    if (exists) {

      setBooks(

        books.map((b) =>

          b.id === book.id ? book : b

        )

      );

    } else {

      setBooks([...books, book]);

    }

    setEditBook(null);

  };

  const deleteBook = (id: number) => {

    setBooks(

      books.filter((book) => book.id !== id)

    );

  };

  const handleEdit = (book: Book) => {

    setEditBook(book);

  };

  const filteredBooks = useMemo(() => {

    return books.filter((book) => {

      const keyword = search.toLowerCase();

      return (

        book.title.toLowerCase().includes(keyword) ||

        book.author.toLowerCase().includes(keyword) ||

        book.category.toLowerCase().includes(keyword)

      );

    });

  }, [books, search]);

  return (

    <main className="flex min-h-screen bg-slate-950 text-white">

      <Sidebar />

      <section className="flex-1">

        <Navbar />

        <div className="p-8">

          <div className="flex justify-between items-center">

            <div>

              <h1 className="text-4xl font-bold">
                Dashboard
              </h1>

              <p className="text-slate-400 mt-2">
                Welcome back! Manage your library efficiently.
              </p>

            </div>

            <div className="flex items-center gap-4">

              <SearchBar
                search={search}
                setSearch={setSearch}
              />

              <AddBookModal
                onSave={saveBook}
                editBook={editBook}
              />

            </div>

          </div>

          <DashboardCards books={books} />

          <BooksTable
            books={filteredBooks}
            onDelete={deleteBook}
            onEdit={handleEdit}
          />

        </div>

      </section>

    </main>

  );

}