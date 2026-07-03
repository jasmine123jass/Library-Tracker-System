"use client";

import { useState } from "react";

interface Props {
  onAdd: (book: any) => void;
}

export default function AddBookModal({ onAdd }: Props) {
  const [open, setOpen] = useState(false);

  const [title, setTitle] = useState("");
  const [author, setAuthor] = useState("");
  const [category, setCategory] = useState("");
  const [year, setYear] = useState("");

  const addBook = () => {
    if (!title || !author || !category || !year) {
      alert("Please fill all fields");
      return;
    }

    onAdd({
      id: Date.now(),
      title,
      author,
      category,
      publishedYear: Number(year),
      status: "Available",
    });

    setTitle("");
    setAuthor("");
    setCategory("");
    setYear("");

    setOpen(false);
  };

  return (
    <>
      <button
        onClick={() => setOpen(true)}
        className="bg-blue-600 hover:bg-blue-700 px-5 py-2 rounded-lg font-semibold"
      >
        + Add Book
      </button>

      {open && (
        <div className="fixed inset-0 bg-black/60 flex justify-center items-center">

          <div className="bg-slate-900 p-8 rounded-xl w-[420px]">

            <h2 className="text-2xl font-bold mb-6">
              Add New Book
            </h2>

            <div className="space-y-4">

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Book Title"
                value={title}
                onChange={(e) => setTitle(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Author"
                value={author}
                onChange={(e) => setAuthor(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Category"
                value={category}
                onChange={(e) => setCategory(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Published Year"
                value={year}
                onChange={(e) => setYear(e.target.value)}
              />

            </div>

            <div className="flex justify-end gap-3 mt-6">

              <button
                onClick={() => setOpen(false)}
                className="px-4 py-2 rounded bg-slate-700"
              >
                Cancel
              </button>

              <button
                onClick={addBook}
                className="px-4 py-2 rounded bg-blue-600"
              >
                Add
              </button>

            </div>

          </div>

        </div>
      )}
    </>
  );
}