"use client";

import { Book } from "@/types/book";

interface Props {
  books: Book[];
  onDelete: (id: number) => void;
  onEdit: (book: Book) => void;
}

export default function BooksTable({
  books,
  onDelete,
  onEdit,
}: Props) {
  return (
    <div className="mt-8 overflow-hidden rounded-xl border border-slate-800 bg-slate-950">

      <table className="w-full">

        <thead className="bg-slate-900">
          <tr>
            <th className="p-4 text-left">Title</th>
            <th className="p-4 text-left">Author</th>
            <th className="p-4 text-left">Category</th>
            <th className="p-4 text-left">Year</th>
            <th className="p-4 text-left">Status</th>
            <th className="p-4 text-center">Actions</th>
          </tr>
        </thead>

        <tbody>

          {books.length === 0 ? (

            <tr>

              <td
                colSpan={6}
                className="text-center py-12 text-slate-400"
              >

                <div className="flex flex-col items-center gap-2">

                  <span className="text-5xl">📚</span>

                  <p className="text-lg font-semibold">
                    No Books Found
                  </p>

                  <p className="text-sm">
                    Click <strong>+ Add Book</strong> to add your first book.
                  </p>

                </div>

              </td>

            </tr>

          ) : (

            books.map((book) => (

              <tr
                key={book.id}
                className="border-t border-slate-800 hover:bg-slate-900 transition-colors"
              >

                <td className="p-4 font-medium">
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
                    className={`px-3 py-1 rounded-full text-sm font-medium ${
                      book.status === "Available"
                        ? "bg-green-600 text-white"
                        : "bg-red-600 text-white"
                    }`}
                  >
                    {book.status}
                  </span>

                </td>

                <td className="p-4 text-center">

                  <button
                    onClick={() => onEdit(book)}
                    className="bg-blue-600 hover:bg-blue-700 px-3 py-1 rounded mr-2 transition"
                  >
                    Edit
                  </button>

                  <button
                    onClick={() => {
                      if (confirm("Delete this book?")) {
                        onDelete(book.id);
                      }
                    }}
                    className="bg-red-600 hover:bg-red-700 px-3 py-1 rounded transition"
                  >
                    Delete
                  </button>

                </td>

              </tr>

            ))

          )}

        </tbody>

      </table>

    </div>
  );
}