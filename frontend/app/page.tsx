"use client";

import { useMemo, useState } from "react";

import Sidebar from "@/components/Sidebar";
import Navbar from "@/components/Navbar";
import DashboardCards from "@/components/DashboardCards";
import BooksTable from "@/components/BooksTable";
import SearchBar from "@/components/SearchBar";

import { books as initialBooks } from "@/data/books";
import { Book } from "@/types/book";

export default function Home() {

  const [books] = useState<Book[]>(initialBooks);

  const [search, setSearch] = useState("");

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

            <SearchBar
              search={search}
              setSearch={setSearch}
            />

          </div>

          <DashboardCards books={books} />

          <BooksTable books={filteredBooks} />

        </div>

      </section>

    </main>

  );

}