"use client";

import { books } from "@/data/books";
import { Pencil, Trash2 } from "lucide-react";

export default function BooksTable() {
  return (
    <div className="mt-10 bg-slate-900 rounded-2xl border border-slate-800 overflow-hidden">

      <div className="flex justify-between items-center p-6 border-b border-slate-800">

        <h2 className="text-2xl font-bold">
          Library Books
        </h2>

        <button className="bg-blue-600 hover:bg-blue-700 px-5 py-2 rounded-xl transition">
          + Add Book
        </button>

      </div>

      <table className="w-full">

        <thead className="bg-slate-800">

          <tr>

            <th className="text-left px-6 py-4">
              Book
            </th>

            <th className="text-left px-6 py-4">
              Author
            </th>

            <th className="text-left px-6 py-4">
              Category
            </th>

            <th className="text-left px-6 py-4">
              Year
            </th>

            <th className="text-left px-6 py-4">
              Status
            </th>

            <th className="text-center px-6 py-4">
              Actions
            </th>

          </tr>

        </thead>

        <tbody>

          {books.map((book) => (

            <tr
              key={book.id}
              className="border-b border-slate-800 hover:bg-slate-800 transition"
            >

              <td className="px-6 py-5 font-semibold">

                {book.title}

              </td>

              <td className="px-6 py-5">

                {book.author}

              </td>

              <td className="px-6 py-5">

                {book.category}

              </td>

              <td className="px-6 py-5">

                {book.publishedYear}

              </td>

              <td className="px-6 py-5">

                {book.status === "Available" ? (

                  <span className="bg-green-600 px-3 py-1 rounded-full text-sm">

                    Available

                  </span>

                ) : (

                  <span className="bg-red-600 px-3 py-1 rounded-full text-sm">

                    Borrowed

                  </span>

                )}

              </td>

              <td className="px-6 py-5">

                <div className="flex justify-center gap-4">

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