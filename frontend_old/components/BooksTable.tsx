"use client";

import { Book } from "@/types/book";
import { Pencil, Trash2 } from "lucide-react";

interface Props {
  books: Book[];
}

export default function BooksTable({ books }: Props) {
  return (
    <div className="mt-8 bg-slate-900 rounded-2xl border border-slate-800 overflow-hidden">

      <div className="flex justify-between items-center p-6 border-b border-slate-800">

        <div>

          <h2 className="text-2xl font-bold">
            Library Books
          </h2>

          <p className="text-slate-400">
            Manage your collection
          </p>

        </div>

        <button
          className="bg-blue-600 hover:bg-blue-700 px-5 py-3 rounded-xl transition"
        >
          + Add Book
        </button>

      </div>

      <table className="w-full">

        <thead className="bg-slate-800">

          <tr>

            <th className="text-left p-4">Title</th>
            <th className="text-left p-4">Author</th>
            <th className="text-left p-4">Category</th>
            <th className="text-left p-4">Year</th>
            <th className="text-left p-4">Status</th>
            <th className="text-center p-4">Actions</th>

          </tr>

        </thead>

        <tbody>

          {books.map((book) => (

            <tr
              key={book.id}
              className="border-b border-slate-800 hover:bg-slate-800 transition"
            >

              <td className="p-4 font-semibold">
                {book.title}
              </td>

              <td className="p-4">
                {book.author}
              </td>

              <td className="p-4">
                {book.category}
              </td>

              <td className="p-4">
                {book.publishedYear}
              </td>

              <td className="p-4">

                <span
                  className={`px-3 py-1 rounded-full text-sm ${
                    book.status === "Available"
                      ? "bg-green-600"
                      : "bg-red-600"
                  }`}
                >
                  {book.status}
                </span>

              </td>

              <td className="p-4">

                <div className="flex justify-center gap-3">

                  <button className="bg-blue-600 p-2 rounded-lg hover:bg-blue-700">

                    <Pencil size={18} />

                  </button>

                  <button className="bg-red-600 p-2 rounded-lg hover:bg-red-700">

                    <Trash2 size={18} />

                  </button>

                </div>

              </td>

            </tr>

          ))}

        </tbody>

      </table>

    </div>
  );
}