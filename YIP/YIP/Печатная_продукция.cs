//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан по шаблону.
//
//     Изменения, вносимые в этот файл вручную, могут привести к непредвиденной работе приложения.
//     Изменения, вносимые в этот файл вручную, будут перезаписаны при повторном создании кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace YIP
{
    using System;
    using System.Collections.Generic;
    
    public partial class Печатная_продукция
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Печатная_продукция()
        {
            this.Заказ = new HashSet<Заказ>();
        }
    
        public int Код_продукции { get; set; }
        public string Название_продукции { get; set; }
        public Nullable<int> Стоимость_еденицы_продукции { get; set; }
        public int Номер_цеха { get; set; }
    
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Заказ> Заказ { get; set; }
        public virtual Цех Цех { get; set; }
    }
}
